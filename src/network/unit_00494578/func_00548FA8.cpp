/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char b[0x800]; };
extern Block D_0086D580;
extern "C" signed char *func_00548D58(signed char *) throw();
extern "C" Block *func_00548A80(int, int) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_005A5CF0(const void *, const void *);
extern "C" unsigned char *func_00548FA8(signed char *name, int sector) {
    unsigned char *base = (unsigned char *)&D_0086D580;
    unsigned char *end = base + 0x800;
    unsigned char *cur = base;
    name = func_00548D58(name);
    for (;;) {
        *(Block *)base = *func_00548A80(sector, 1);
        unsigned char *prev = cur;
        while (cur < end) {
            if (func_005A5CF0(name, cur + 0x21) == 0) return cur;
            if (*cur == 0) return 0;
            prev = cur;
            cur = prev + *prev;
        }
        unsigned size = prev - end;
        ++sector;
        cur = base - size;
        func_005A4724(cur, prev, size);
    }
}
