typedef int s32;

struct S {
    s32 w0;
    s32 w1;
};

struct R {
    s32 pad0;
    s32 val;
};

struct O {
    s32 pad0;
    struct R *rd;
};

extern char MfloatReader__vtable[];

extern "C" s32 func_0024DB78(struct S *arg0, s32 arg1);
extern "C" void MReaderBase__structor_0(struct S *arg0, s32 arg1);

extern "C" void MfloatReader__structor_15(struct O *arg0, s32 arg1, s32 arg2) {
    struct S s;
    struct R *r;
    s32 v;
    s32 tag;

    tag = (s32)MfloatReader__vtable;
    arg2 = arg2 * 4;
    r = arg0->rd;
    v = r->val;
    s.w0 = tag;
    s.w1 = v + arg2;
    func_0024DB78(&s, arg1);
    s.w0 = tag;
    MReaderBase__structor_0(&s, 0);
}
