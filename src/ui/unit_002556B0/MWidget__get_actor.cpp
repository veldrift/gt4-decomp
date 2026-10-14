extern "C" void func_001FEF50(void *, int);
extern "C" void func_002550B8(void *, int) throw();
extern "C" void func_00255110(void *, void *) throw();
extern "C" void func_00266C18(void *, int, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void MWidget__get_actor(int *dst, void *arg1, int n, void *arg3) {
    int buf[4];
    int temp[4];
    int value = 0;
    if (n > 0) {
        func_002FC8C8(buf, arg3);
        value = func_002FE250(buf[0]);
        func_002FC870(buf, 2);
    }
    func_00255110(buf, arg1);
    int *p = temp;
    func_00266C18(p, buf[0], value);
    if (dst != p) {
        int v = *p;
        if (v) func_003285A8(v);
        int old = *dst;
        if (old) func_003285F8(old);
        *dst = v;
    }
    func_001FEF50(p, 2);
    func_002550B8(buf, 2);
}
