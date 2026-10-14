/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { void *vt; char pad[0x6C]; };
extern "C" void func_0044EEA8(void *);
extern "C" void func_0044F0F8(void *, int, float);
extern "C" void func_0044E660(int, int, void *, int, int, int) throw();
extern "C" void CameraBase__structor_1(void *, int);
extern char D_006883F8[];
extern "C" void func_0044E9A0(int a0, int a1, int a2, int a3, int t0, int t1, float f) {
    Cam c;
    func_0044EEA8(&c);
    func_0044F0F8(&c, a2, f);
    func_0044E660(a0, a1, &c, a3, t0, t1);
    c.vt = D_006883F8;
    CameraBase__structor_1(&c, 0);
}
