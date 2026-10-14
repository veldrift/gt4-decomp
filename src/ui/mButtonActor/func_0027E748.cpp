typedef int s32;
typedef float f32;

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
struct H16 {
    struct Obj *p;
    char pad[0xC];
};
struct I16 {
    s32 v;
    char pad[0xC];
};

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *, s32);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct Self {
    char pad0[0x14];
    void *wid;
    Obj *obj;
    char pad1c[4];
    s32 f20;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 f34;
};

extern Rep D_00659FA8;
extern char D_0069A908[];

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0025B500(void *w, f32 *a, f32 *b, f32 *c, f32 *d);
extern "C" void func_00284B18(void *arg0, int arg1);
extern "C" int func_002864F8(void *arg0);
extern "C" void func_003069F8(void *arg0, void *arg1, void *arg2);
extern "C" s32 HSymID__GetID(Str *s);

extern "C" void func_0027E748(Self *a, void *arg1) {
    H16 h;
    I16 id;
    Str s;
    a->wid = arg1;
    a->f20 = 0;
    func_0025B500(arg1, &a->x, &a->y, &a->w, &a->h);
    func_002864F8(&h);
    {
        Str *ps = &s;
        const char *src = D_0069A908;
        Rep *r = &D_00659FA8;
        char *d;
        d = (char *)(r + 1);
        I16 *pid = &id;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        pid->v = HSymID__GetID(ps);
        func_003069F8(a->wid, &h, pid);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    if (h.p != 0) {
        a->obj = h.p;
    }
    {
        Obj *o = a->obj;
        VEntry *e = (VEntry *)(o->vtbl + 0x1C8);
        a->f34 = e->fn((char *)o + e->delta, 0);
    }
    func_00284B18(&h, 2);
}
