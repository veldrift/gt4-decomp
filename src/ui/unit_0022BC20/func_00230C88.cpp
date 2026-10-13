extern char D_0082E550[]; /* mutex */
extern "C" void func_005769F0(int arg0);
extern "C" void func_00576A28(int arg0);

extern "C" void func_00230C88(void *arg0)
{
    float zero[4];
    float *p;
    float z;

    func_005769F0((int)D_0082E550);
    z = 0.0f;
    p = (float *)((char *)arg0 + 0x1D14);
    zero[0] = z;
    zero[1] = z;
    zero[2] = z;
    zero[3] = z;
    if (p != zero) {
        p[0] = z;
        p[1] = z;
        p[2] = z;
        p[3] = z;
    }
    func_00576A28((int)D_0082E550);
}
