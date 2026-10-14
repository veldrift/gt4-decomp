extern "C" void func_001FEF20(void *, void *);
extern "C" void func_001FEF50(void *, int);
extern "C" void func_001FEFA8(void *, void *);
extern "C" void func_002550B8(void *, int) throw();
extern "C" void func_00255110(void *, void *) throw();
extern "C" void func_00266D20(int, void *, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(int);
extern "C" void MWidget__set_actor(void *unused, void *arg1, int n, int *arg3) {
    int buf[4];
    int temp[4];
    int zero[4];
    if (n > 0) {
        int value = 0;
        if (n >= 2) {
            func_002FC8C8(buf, arg3 + 1);
            value = func_002FE250(buf[0]);
            func_002FC870(buf, 2);
        }
        func_00255110(buf, arg1);
        if (*arg3 == 0) {
            int *p = temp;
            int obj = buf[0];
            zero[0] = 0;
            func_001FEF20(p, zero);
            func_00266D20(obj, p, value);
            func_001FEF50(p, 2);
        } else {
            int *p = temp;
            func_001FEFA8(p, arg3);
            func_00266D20(buf[0], p, value);
            func_001FEF50(p, 2);
        }
        func_002550B8(buf, 2);
    }
}
