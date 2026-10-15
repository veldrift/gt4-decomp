/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char b[11]; };
extern "C" void func_005A48D8(void *, int, unsigned);
extern "C" void *func_0043C608(void *s, void *d) {
    func_005A48D8(d, 0, 12);
    *(Block *)d = *(const Block *)((char *)s + 16);
    return (char *)d + 12;
}
