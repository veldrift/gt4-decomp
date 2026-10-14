extern "C" float func_00496EF0(void *, float *, float *);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A6F10(int, int);
extern "C" void func_004A74A0();
extern "C" int func_00497C48(void *, int, float, float, float, float);
extern "C" int func_00498518(void *self, void *p, float num, float nf) {
    int n = (int)nf;
    float ax, ay;
    func_004A53F8();
    func_004A74A0();
    float r = func_00496EF0(p, &ax, &ay);
    func_004A5400();
    int ret = 0;
    if (!(r < -1.0f) && !(r > 1.0f)) {
        func_004A6F10(0, 0);
        ret = func_00497C48(self, 0, ax, ay, (float)n, num / (float)(n * n));
    }
    return ret;
}
