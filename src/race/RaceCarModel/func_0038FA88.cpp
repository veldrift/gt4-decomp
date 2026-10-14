/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Raw { s32 a; s32 b; s32 vt; };
struct VEnt { short delta; short index; void (*fn)(char *); };
extern "C" s32 func_003B1B88(char *, char *, ...);
extern "C" s32 func_003ED9F0(void);
extern "C" void func_00450AE8(char *, char *, s32);
extern "C" char *func_0038FA88(char *self, char *src) {
    s32 spill[4];
    VEnt *e = (VEnt *)(*(char **)(self + 8) + 0x10);
    e->fn(self + e->delta);
    s32 old = *(s32 *)(self + 8);
    *(Raw *)self = *(Raw *)src;
    *(s32 *)(self + 8) = old;
    spill[0] = old;
    *(s32 *)(self + 0x1668) = *(s32 *)(src + 0x1668);
    *(s32 *)(self + 0x166C) = *(s32 *)(src + 0x166C);
    func_00450AE8(self + 0x18, src + 0x18, func_003ED9F0());
    VEnt *e2 = (VEnt *)(*(char **)(self + 8) + 0x80);
    e2->fn(self + e2->delta);
    s32 t = *(s32 *)(src + 0x1670);
    *(s32 *)(self + 0x1670) = t;
    *(s32 *)(self + 0x1674) = *(s32 *)(src + 0x1674);
    func_003B1B88(self + 0x5E0, src + 0x5E0, t);
    func_003B1B88(self + 0xE20, src + 0xE20);
    return self;
}
