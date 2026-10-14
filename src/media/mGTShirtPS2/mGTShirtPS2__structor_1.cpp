/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E1C { char b[0x1C]; };
struct E4C { char b[0x4C]; };
extern char mGTShirtPS2__vtable[];
extern char D_00693C80[];
extern "C" void func_00574EE8(void *);
extern "C" void func_00578908(s32);
extern "C" void func_00578AF0(s32);
extern "C" void func_001C20A0(void *) throw();
extern "C" void func_001C21A8(void *) throw();
extern "C" void free(s32) throw();
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_002550B8(void *, s32);
extern "C" void mGTShirt__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mGTShirtPS2__structor_1(char *self, s32 flags) {
    E1C *s0 = (E1C *)(self + 0x80);
    E4C *s1 = (E4C *)(self + 0x10C);
    char *s4 = self + 0x2E0;
    *(char **)(self + 4) = mGTShirtPS2__vtable;
    *(s32 *)(self + 0x318) = 1;
    func_00574EE8(s4);
    func_00578908(*(s32 *)(self + 0x310));
    func_00578AF0(*(s32 *)(self + 0x310));
    *(s32 *)(self + 0x310) = 0;
    func_001C20A0(self + 0xF0);
    for (s32 i = 0; i < 4; ++i) {
        func_001C20A0(&s0[i]);
        func_001C21A8(&s1[i]);
    }
    E1C *p = (E1C *)(self + 0x10);
    s32 j = 3;
    do {
        func_001C20A0(p++);
    } while (--j >= 0);
    free(*(s32 *)(self + 0x264));
    func_00574DA8(s4, 2);
    func_002550B8(self + 0x2DC, 2);
    mGTShirt__structor_1(self, 0);
    if (flags & 1) return func_00326798(self, 0x32C, 4, D_00693C80);
}
