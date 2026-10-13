extern "C" void func_0057D9C0(const char *fmt, ...);

extern char D_006C1498[];
extern int D_0064A2C0;
extern void (*D_0064A2CC)(int, int);

void func_00507098(void) {
    int temp_s0;
    void (*temp_v0)(int, int);

    temp_s0 = D_0064A2C0;
    func_0057D9C0(D_006C1498);
    temp_v0 = D_0064A2CC;
    if (temp_v0 != 0) {
        temp_v0(0, temp_s0);
    }
}
