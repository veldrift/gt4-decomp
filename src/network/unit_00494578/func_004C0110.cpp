/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C0208(int, int, int, int, int);
extern "C" int func_004C0A28(int, int *);
extern "C" void func_004C8C38(int, int);

extern "C" int func_004C0110(int a0, int a1, int a2, int a3) {
    int tmp;
    int n = a1 & 0xFFFF;
    int total = 0;
    int r = func_004C0A28(a0, &tmp);
    if (r < 0) {
        return -1;
    }
    if (a2 == 1) {
        func_004C0208(a0, n, 1, tmp, r);
    }
    if (a3 > 0) {
        do {
            int x = func_004C0208(a0, n, 2, tmp, r);
            total += x;
            if (x < 0) {
                if (r > 0) {
                    func_004C8C38(a0, tmp);
                }
                return x;
            }
        } while (total < a3);
    }
    if (r > 0) {
        func_004C8C38(a0, tmp);
    }
    return 0;
}
