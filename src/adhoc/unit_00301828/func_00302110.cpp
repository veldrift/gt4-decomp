typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void * func_005C2630(void *, s32, s32, void *, s32);
extern "C" void * func_00306E00(void *, void *);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003068A8(s32, void *, void *);
extern "C" void func_003041A0(void *, void *);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_00301FE0(void);
extern "C" void func_00302078(void);

extern char D_0069DB40[];
extern char D_0069DB48[];
extern char D_0069DB50[];

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void * func_00302110(s32 *arg0) {
    s32 buf0[4];
    Str s1;
    Str s2;
    {
    Str *p = &s2;
    char *v = (char *)&D_0069DB40;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_00306E00(buf0, p);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DB48;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, (void *)func_00301FE0);
    str_release(p);
    }
    {
    char *v = (char *)&D_0069DB50;
    s32 h = buf0[0];
    Str *p = &s1;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p->p = d;
    }
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));
    func_003068A8(h, p, (void *)func_00302078);
    str_release(p);
    }
    func_003041A0(arg0, buf0);
    func_003041B8(buf0, 0x2);
    return arg0;
}
