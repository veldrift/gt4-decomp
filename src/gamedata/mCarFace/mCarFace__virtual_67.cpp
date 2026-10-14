/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Handle {
    s32 p;
    char pad[0xC];
};

struct Self {
    char padCC[0xCC];
    s32 fCC;
    char padD0[0x2A4 - 0xD0];
    s32 f2A4;
    char pad2A8[0x8];
    s32 f2B0;
    s32 f2B4;
};

extern "C" void func_0013A370(Str *ret, void *arg1);
extern "C" void func_0013ACC8(void *arg0, s32 arg1);
extern "C" void func_00151830(void *arg0, int arg1);
extern "C" void func_00151BD0(void *arg0);
extern "C" void func_00210710(void *arg0, int arg1);
extern "C" void func_0025A7E0(void *arg0, void *arg1);
extern "C" void mTextFace__virtual_67(void *arg0);
extern "C" void func_0026A118(void *arg0, int arg1);
extern "C" void func_0026A990(void *ret, s32 obj, Str *key, int cached, int a, int b);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void assign(s32 *dst, Handle *src) {
    if (dst != (s32 *)src) {
        s32 newVal = src->p;
        s32 oldVal;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
}

extern "C" void mCarFace__virtual_67(Self *arg0) {
    Str a;
    Handle ref;
    Handle h;
    Str b;
    s32 nonempty;
    s32 *p;
    mTextFace__virtual_67(arg0);
    p = &arg0->f2A4;
    if (*p == 0) {
        func_00151BD0(&a);
        assign(p, (Handle *)&a);
        func_00151830(&a, 2);
    }
    func_0013A370(&a, arg0);
    {
        Rep *q = (Rep *)(a.p - 0x10);
        nonempty = q->len != 0;
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    if (nonempty) {
        p = &arg0->fCC;
        if (*p == 0) {
            Handle *ph = &h;
            Handle *pr = &ref;
            Str *pb;
            s32 obj;
            func_0025A7E0(ph, arg0);
            obj = ph->p;
            pb = &b;
            func_0013A370(pb, arg0);
            func_0026A990(pr, obj, pb, 1, 0, 1);
            assign(p, pr);
            func_00210710(pr, 2);
            {
                Rep *q = (Rep *)(pb->p - 0x10);
                if (--q->ref == 0) {
                    s32 size = q->cap + 0x10;
                    func_00326798(q, size, 4, func_005C11A8()->name);
                }
            }
            func_0026A118(ph, 2);
        }
    }
    func_0013ACC8(arg0, arg0->f2B4);
    arg0->f2B0 = 0;
}
