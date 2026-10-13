typedef int s32;
typedef float f32;
typedef unsigned char s8;

extern "C" char D_00666D20[];

struct S {
    void *vtbl;
    void *self;
};

extern "C" s32 func_0024DB78(S *obj, s32 reader);
extern "C" void func_0020FCE0(S *obj, s32 arg1);

extern "C" f32 func_00261E08(s32 arg0) {
    s8 buf[0x10];
    S s;
    S *ps = &s;
    f32 r;

    ps->vtbl = D_00666D20;
    ps->self = (void *)buf;
    func_0024DB78(ps, arg0);
    r = *(f32 *)buf;
    ps->vtbl = D_00666D20;
    func_0020FCE0(ps, 0);
    return r;
}
