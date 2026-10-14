/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_00496EF0(void *, float *, float *) throw();
extern "C" int func_00497C48(void *, int, float, float, float, float) throw();
extern "C" void func_004A1638(int);
extern "C" char D_006AF5E0[];
extern "C" int func_00497FD0(void *self, float num, float size) {
    float ax, ay;
    float r = func_00496EF0(D_006AF5E0, &ax, &ay);
    int ret = 0;
    if (!(r < -1.0f) && !(r > 1.0f)) {
        if (size < 2.0f) size = 2.0f;
        func_004A1638(5);
        int n = (int)size;
        ret = func_00497C48(self, 0, ax, ay, size, num / (float)(n * n));
    }
    return ret;
}
