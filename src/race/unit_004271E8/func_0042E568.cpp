/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" char *func_00472680(int *, unsigned int);
extern "C" float func_00472940(int *, float);
extern "C" int func_005A5A30(char *, unsigned int, const char *, ...);
extern int PDISTD__UNIT_MANAGER[];
extern char D_006A4FA8[];
extern char D_006A4FB0[];

extern "C" void func_0042E568(char *buf, unsigned int size, float x) {
    char *name = func_00472680(PDISTD__UNIT_MANAGER, size);
    if (x == 0.0f) {
        func_005A5A30(buf, size, D_006A4FA8, name);
        return;
    }
    float v = func_00472940(PDISTD__UNIT_MANAGER, x);
    int n = (int)(v * 100.0f);
    int r = n % 100;
    int q = n / 100;
    func_005A5A30(buf, size, D_006A4FB0, q, r, name);
}
