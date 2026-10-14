typedef int s32;
typedef float f32;
typedef unsigned char s8;

extern "C" char MfloatReader__vtable[];

struct S {
    void *vtbl;
    void *self;
};

extern "C" s32 func_0024DB78(S *obj, s32 reader);
extern "C" void MReaderBase__structor_0(S *obj, s32 arg1);

extern "C" f32 MfloatReader__structor_5(s32 arg0) {
    s8 buf[0x10];
    S s;
    S *ps = &s;
    f32 r;

    ps->vtbl = MfloatReader__vtable;
    ps->self = (void *)buf;
    func_0024DB78(ps, arg0);
    r = *(f32 *)buf;
    ps->vtbl = MfloatReader__vtable;
    MReaderBase__structor_0(ps, 0);
    return r;
}
