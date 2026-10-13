typedef int s32;

extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" s32 func_001467A0(void *self);

extern "C" s32 func_00146B10(void *arg0, void *arg1) {
    s32 a[4];
    s32 b[4];
    s32 *pb;
    s32 x;
    s32 y;
    s32 res;

    func_0013BDC0(a, arg0);
    x = func_001467A0((void *)a[0]);
    pb = b;
    func_0013BDC0(pb, arg1);
    y = func_001467A0((void *)pb[0]);
    res = x < y;
    func_0013BD68(pb, 2);
    func_0013BD68(a, 2);
    return res;
}
