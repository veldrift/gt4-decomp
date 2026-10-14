# How we are recovering the CarData functions

Think of this as reconstructing a recipe from a finished cake, with an unusually useful test: we can run our proposed recipe through the same old compiler and compare its output with the game instruction by instruction.

We have the game's executable, which contains PS2 machine instructions. It does not contain the original C++ source. The repository also has recovered names, existing matching functions, and tools for disassembling the executable. Those give us starting points. We have not downloaded or imported GTHD debug symbols for this batch.

## What I do for each function

1. **Find its boundaries and callers.** An address such as `00130618` identifies where a function starts. Calls show which other routines it uses. Script registration gives many of the MCarData method names. Unnamed helpers keep address-based names until there is enough evidence for a better name.
2. **Read the assembly for behavior.** Loads and stores reveal fields and temporary buffers; branches reveal checks and loops; calls reveal operations such as looking up a car, constructing a string, or wrapping a result for the scripting system. I track what is stored at each stack offset and which values survive calls.
3. **Use an existing match as a reference.** GetPrice already demonstrates the script argument, string, result-handle and cleanup conventions. That lets us reuse a verified pattern rather than invent the entire interface again.
4. **Write a plausible C++ reconstruction in scratch files.** m2c can propose a draft, but it often guesses types or stack objects incorrectly. I correct those guesses against the instructions and recovered neighboring sources. Scratch drafts stay outside `src/` until they match.
5. **Compile it with Sony's old ee-gcc.** A modern compiler would arrange the instructions differently. The project uses the original-era compiler and its configured flags so that an exact comparison is meaningful.
6. **Read the differences and revise the source.** If our version has an extra call, the reconstructed behavior may be wrong. If it uses a different register or moves an instruction into a different branch slot, the behavior may be right but the source structure, type, or object lifetime may still differ.
7. **Accept an exact match, then validate the whole image.** The individual judge must say MATCH. The full build must also preserve the original code and data hashes and link the new function from source. This second check catches address, data-placement and integration problems that an isolated comparison cannot settle.

## A concrete example from this batch

The small score-range search at `00130618` compares a target score with the middle of a sorted range, then searches one half. My first reconstruction used a loop. It performed the expected search, but three instructions differed.

Writing it as a function that calls itself on the chosen half produced an exact match. The old compiler optimizes those final self-calls into jumps, so the executable still contains a loop. This is why copying what the assembly superficially looks like is not always enough: we also have to work backward through what the compiler does to source code.

Another example is GetCarLogoName. Writing a shared block explicitly initially produced different code. Writing out the original branches separately let the compiler merge their common instructions itself, and that version matched. We are aiming for source that explains the original result, not manually specifying individual processor instructions.

## Why the counts can stay still for a while

A function can do the correct operation and still fail an exact-match test. A string may be destroyed one statement too early, an integer may be signed instead of unsigned, or a conditional may be written in a form that the old compiler handles differently. One small change can move a whole stretch of instructions, making the raw difference count look worse than the actual reconstruction gap.

That is why I also align instruction sequences and inspect actual branch destinations. In the eligibility helper at `001307E8`, one parser-failure branch exits the entire function. Treating it as merely ending the inner loop was a behavioral mistake; checking the destination exposed it and the corrected source matched.

For stubborn small differences, we can use decomp-permuter to try equivalent source arrangements. Its candidates still have to pass the ordinary exact-match judge and full build. This batch is AI-assisted, with manual assembly analysis, m2c drafts, and bounded permuter experiments. The accepted sources do not use inline assembly or pinned registers.

## What this work gives us

Each accepted function replaces a piece of the original executable with readable C or C++ that reproduces its machine code. Recovering smaller helpers also clarifies the larger functions' inputs, outputs and record layouts. It does not automatically make callers match, and a byte-identical reconstruction does not prove we have recovered the original author's exact wording or every field's original name.

This is a matching decompilation workflow. It is different from recompiling the original instructions to run on another platform: here the immediate goal is to recover source while retaining the original PS2 output exactly.
