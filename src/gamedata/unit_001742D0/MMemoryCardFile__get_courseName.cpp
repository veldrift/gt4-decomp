typedef int s32;
typedef unsigned int u32;

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

struct Obj {
    void *p;
    char pad[0xC];
};

struct Handle {
    s32 v;
    char pad[0xC];
};

struct Vt {
    short delta;
    short index;
    void *fn;
};

struct Inner {
    char pad0[0x4C];
    Vt *tab;
};

struct Outer {
    char pad0[0x10];
    Inner *in;
};

extern Rep D_00659FA8;
extern char D_005D15A8[];
extern char D_005D1260[];
extern char D_00690D18[];

extern "C" void func_00174148(void *arg0, void *arg1);
extern "C" void func_001740F0(void *arg0, int arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_0057F260(const char *s);
extern "C" Inner *GT4MC__FileGT4GameData__loadInstance(void *arg0, const char *arg1, int arg2, void *arg3, const char *arg4, Inner *arg5);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

static inline void release(Str *ps)
{
    Rep *q = (Rep *)(ps->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

static inline void assign(s32 *dst, Handle *h)
{
    if (dst != &h->v) {
        s32 newVal = h->v;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *dst;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *dst = newVal;
    }
}

extern "C" void MMemoryCardFile__get_courseName(s32 *arg0, void *arg1) {
    Obj h0;
    Handle tmp;
    Str s1;
    Str s2;
    Inner *in;
    Inner *a1;

    func_00174148(&h0, arg1);
    in = ((Outer *)h0.p)->in;
    a1 = 0;
    if (in != 0) {
        a1 = GT4MC__FileGT4GameData__loadInstance(in->tab->fn, D_005D15A8, 0, (char *)in + in->tab->delta, D_005D1260, in);
    }
    if (a1 != 0) {
        Str *ps = &s1;
        const char *name;
        Vt *e = (Vt *)((char *)a1->tab + 0x98);
        name = ((char *(*)(void *))e->fn)((char *)a1 + e->delta);
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            *(s32 *)&ps->p = (s32)d;
        }
        func_005C2630(ps, 0, -1, name, func_0057F260(name));
        Handle *ph = &tmp;
        func_00314B20(ph, ps);
        assign(arg0, ph);
        func_00312318(ph, 2);
        release(ps);
    } else {
        const char *lit = D_00690D18;
        Str *ps = &s2;
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, lit, func_0057F260(lit));
        Handle *ph = &tmp;
        func_00314B20(ph, ps);
        assign(arg0, ph);
        func_00312318(ph, 2);
        release(ps);
    }
    func_001740F0(&h0, 2);
}
