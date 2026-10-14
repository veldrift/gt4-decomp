/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_0026DB50(char *);
extern "C" int func_0055EFC8(void *, int);

extern "C" int mUpdateContextPS2__virtual_58(char *self, int idx) {
    void *p = func_0026DB50(self + idx * 0xD4 + 0x1A0);
    int r = func_0055EFC8(p, 0) != 0;
    if (func_0055EFC8(p, 1)) r |= 0x2;
    if (func_0055EFC8(p, 2)) r |= 0x4;
    if (func_0055EFC8(p, 3)) r |= 0x8;
    if (func_0055EFC8(p, 6)) r |= 0x4000;
    if (func_0055EFC8(p, 7)) r |= 0x8000;
    if (func_0055EFC8(p, 12)) r |= 0x10;
    if (func_0055EFC8(p, 13)) r |= 0x20;
    if (func_0055EFC8(p, 14)) r |= 0x40;
    if (func_0055EFC8(p, 15)) r |= 0x80;
    if (func_0055EFC8(p, 16)) r |= 0x100;
    if (func_0055EFC8(p, 17)) r |= 0x200;
    if (func_0055EFC8(p, 18)) r |= 0x400;
    if (func_0055EFC8(p, 19)) r |= 0x800;
    if (func_0055EFC8(p, 20)) r |= 0x1000;
    if (func_0055EFC8(p, 21)) r |= 0x2000;
    if (func_0055EFC8(p, 4)) r |= 0x10000;
    if (func_0055EFC8(p, 5)) r |= 0x20000;
    if (func_0055EFC8(p, 9)) r |= 0x40000;
    if (func_0055EFC8(p, 10)) r |= 0x80000;
    if (func_0055EFC8(p, 11)) r |= 0x100000;
    return r;
}
