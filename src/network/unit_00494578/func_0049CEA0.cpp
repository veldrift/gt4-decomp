/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0049CC48(void *) throw();
extern "C" void func_0049E228(void *);
extern int D_00624C74, D_00624C78, D_00624C7C, D_00624C80;
extern char *D_0084AF58, *D_0084AF5C, *D_0084AF60, *D_0084AF64;
extern "C" void func_0049CEA0(int arg0) {
    int a = arg0 & 0x1ff;
    int b = (arg0 >> 9) & 0x7f;
    if (a == 0x1ff) a += D_00624C7C;
    if (a != 0 && a != D_00624C74) {
        if (a >= 0x1ff) {
            char *p = D_0084AF60;
            if (p) func_0049CC48(p + D_00624C7C * 40);
        } else {
            char *p = D_0084AF58;
            if (p) func_0049CC48(p + a * 40 - 40);
        }
        D_00624C74 = a;
    }
    if (b == 0x1ff) b += D_00624C80;
    if (b != 0 && b != D_00624C78) {
        if (b >= 0x7f) {
            char *p = D_0084AF64;
            if (p) func_0049E228(p + D_00624C80 * 80);
        } else {
            char *p = D_0084AF5C;
            if (p) func_0049E228(p + b * 80 - 80);
        }
        D_00624C78 = b;
    }
}
