typedef unsigned char u8;
extern "C" u8 *func_0021A850(u8 *);
extern "C" float func_0057B0A0(float, float, float, float, float);
extern "C" void func_002BD258(u8 *self) {
    int i = 0;
    float *dst = (float *)func_0021A850(self + 0xA0);
    for (; i < 3; i++) {
        float *src = (float *)(self + 0x2F0);
        float *p = dst + i;
        float *q = src + i;
        *p = func_0057B0A0(*p, *q, 0x1.999998p-5f, -180.0f, 180.0f);
    }
}
