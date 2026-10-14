/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
extern char D_00688960[];
extern "C" void func_0046F688(void *);
extern "C" void func_005C1628(void *);
extern "C" void func_0046F5C8(char *self, s32 flags) {
    *(char **)(self + 0xA7C) = D_00688960;
    do { func_0046F688(self); } while (0);
    char *a = self + 0x2C;
    char *p = self + 0x444;
    if (a != (char *)-0x100) {
        if (self + 0x12C != p) {
            do {
                p -= 0x108;
                char *t = *(char **)(p + 0x104) + 8;
                ((void (*)(void *, s32))*(void **)(t + 4))(p + *(short *)t, 2);
            } while (self + 0x12C != p);
        }
    }
    if (flags & 1) return func_005C1628(self);
}
