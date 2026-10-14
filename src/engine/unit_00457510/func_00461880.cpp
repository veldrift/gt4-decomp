/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char D_008468E8[];
extern "C" char *D_008468E4;
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" int func_004616E8(int, int, float, int) throw();
extern "C" void func_0055C020(char *, int, float, float);
extern "C" void func_00461880(int a, float x, int b, float y, int c) {
    func_00576788(D_008468E8);
    if (func_004616E8(a, b, y, c)) {
        func_0055C020(D_008468E4, 0, 1.0f, x);
    }
    func_005767C0(D_008468E8);
}
