typedef int s32;
extern "C" char D_008468E8[];
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00461808(void *s, int a, float f, int b);
extern "C" int func_00461928(void *s, int a, float f, int b);
extern "C" void func_00461978(void *s, int a, int b, float f) {
    int r;
    func_00576788(D_008468E8);
    r = func_00461928(s, a, f, b);
    if (r >= 0) {
        func_00461808((void *)r, a, f, b);
    }
    func_005767C0(D_008468E8);
}
