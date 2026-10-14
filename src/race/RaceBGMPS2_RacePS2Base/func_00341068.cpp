/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(char *);
};

extern "C" void func_00105280(void *, s32);
extern "C" s32 func_001052E0(void *, s32, s32, s32);
extern "C" void GSBuffer__getTexture(void *, void *);
extern "C" void *func_0038F2C0(void *, void *, s32);
extern "C" void *func_0038F348(void *, void *, s32);
extern "C" void func_00397320(void *, void *);
extern "C" void func_003D6480(void *, void *, void *, float);
extern "C" void func_003D6908(void *, void *);
extern "C" void func_003D6930(void *);
extern "C" void func_003D6980(void *, void *, float);
extern "C" void func_004568C0(void *);
extern "C" void *func_0049CE00(void *, float);

extern "C" void func_00341068(char *arg0, char *arg1, void *arg2, float fp0) {
    char sp[0xF0];
    char *s4 = *(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4);
    func_001052E0(sp, 0, 0x100, 0x100);
    char *p40 = sp + 0x40;
    *(char **)p40 = sp;
    func_003D6908(p40, func_0038F348(arg2, sp + 0xA0, 0));
    func_003D6480(p40, func_0038F2C0(arg2, sp + 0xB0, 0), *(void **)(arg1 + 0x2880), fp0);
    VEntry *e = (VEntry *)(*(char **)(arg0 + 0x64) + 0x488);
    if (e->fn(arg0 + e->delta) == 0) {
        func_003D6980(p40, *(void **)(arg1 + 0x2880), fp0);
    } else {
        void *s1 = func_0049CE00(p40, fp0);
        GSBuffer__getTexture(sp, sp + 0xC0);
        func_004568C0(sp + 0xC0);
        func_003D6930(p40);
        func_00397320(s4, sp + 0x84);
        func_004568C0(s1);
    }
    func_00105280(sp, 2);
}
