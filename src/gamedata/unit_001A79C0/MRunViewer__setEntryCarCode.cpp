#include "types.h"

struct Ref { s32 p; s32 pad[3]; };
struct Rep { s32 len, cap, ref, sel; };
extern "C" void func_001A7780(void *, void *);
extern "C" void func_001A7728(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" void func_00312370(void *, void *);
extern "C" void func_00312318(void *, s32);
extern "C" char **func_00314920(void *);
extern "C" void func_00427600(s32, s32, s32);
extern "C" char D_00692C08[];

extern "C" void MRunViewer__setEntryCarCode(void *self, void *arg1, s32 count, s32 arg3) {
    if (count < 2) return;
    s32 current[4];
    s32 entry[4];
    s32 code[4];
    func_001A7780(current, arg1);
    s32 *pEntry = entry;
    func_002FC8C8(pEntry, (void *)arg3);
    s32 *pCode = code;
    func_00312370(pCode, (void *)(arg3 + 4));
    s32 selected = *(s32 *)((char *)(void *)current[0] + 0x10);
    s32 value = func_002FE250(*pEntry);
    char **slot = func_00314920((void *)*pCode);
    char *text = *slot;
    s32 length = ((Rep *)text - 1)->len;
    const char *result = D_00692C08;
    if (length != 0) {
        text[length] = 0;
        result = *slot;
    }
    func_00427600(selected, value, (s32)result);
    func_00312318(pCode, 2);
    func_002FC870(pEntry, 2);
    func_001A7728(current, 2);
}
