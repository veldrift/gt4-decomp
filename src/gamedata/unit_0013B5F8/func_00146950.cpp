typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x174];
    s32 f;
};

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" f32 func_001465D8(struct Obj *arg0);

extern "C" s32 func_00146950(void *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *q;
    s32 r;
    struct Obj *p0;
    struct Obj *p1;
    f32 t0;
    f32 t1;
    f32 d;

    r = 1;
    func_0013BDC0(buf0, arg0);
    p0 = (struct Obj *)buf0[0];
    d = func_001465D8(p0);
    t0 = (f32)p0->f / d;
    q = buf1;
    func_0013BDC0(q, arg1);
    p1 = (struct Obj *)q[0];
    d = func_001465D8(p1);
    t1 = (f32)p1->f / d;
    if (!(t0 < t1)) {
        r = 0;
    }
    func_0013BD68(q, 2);
    func_0013BD68(buf0, 2);
    return r;
}
