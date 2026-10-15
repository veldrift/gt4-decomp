/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7A54(void);
extern "C" void func_004A7AA8(void *, void *);
extern char D_006AA8D0[];

extern "C" int func_004535A0(int flag, float a, float b) {
    float v[3];
    if (b < 0.0f)
        return 1;
    func_004A53F8();
    func_004A7A54();
    func_004A7AA8(v, D_006AA8D0);
    func_004A5400();
    float nb = -b;
    if (flag)
        v[0] = -v[0];
    float t = (a / b) * v[0] + a;
    if (nb < v[0]) {
        return t * t < v[1] * v[1] + v[2] * v[2];
    }
    return 1;
}
