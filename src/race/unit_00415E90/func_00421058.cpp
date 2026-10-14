/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0057D8A0(float, float *, float *);
extern "C" void func_00421058(float *arg0, float *arg1, float *arg2) {
    float t = *arg0;
    float buf[4];
    buf[0] = t;
    func_0057D8A0(t, arg1, arg2);
}
