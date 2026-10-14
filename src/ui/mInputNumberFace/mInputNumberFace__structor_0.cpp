/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { s32 p; };
struct Sub { s32 f0, f4, f8, fC, f10; };

struct Self {
    char pad0[4];
    char *vt;
    char pad8[0x98];
    char sub0[0x64];
    Str str;
    Sub sub;
    s32 f11C, f120;
};

extern Rep D_00659FA8;
extern char mInputNumberFace__vtable[];
extern char D_0069B8C0[];
extern "C" void func_00246F58(void *);
extern "C" s32 mWidget__structor_0(void *);
extern "C" void func_00265F10(void *, int);
extern "C" void func_00268450(void *, int);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_0057CD90(void *, int, int);
extern "C" void func_0057CE40(void *, int);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

extern "C" void mInputNumberFace__structor_0(Self *self) {
    Str *ps = &self->str;
    mWidget__structor_0(self);
    self->vt = mInputNumberFace__vtable;
    func_00246F58(self->sub0);
    {
        Rep *d = &D_00659FA8;
        char *p;
        if (d->sel != 0) {
            p = func_005C2560(d);
        } else {
            p = (char *)d + 0x10;
            d->ref++;
        }
        ps->p = (s32)p;
    }
    Sub *sub = &self->sub;
    sub->f8 = 1;
    sub->fC = 1;
    sub->f0 = 0;
    sub->f4 = 0;
    sub->f10 = 0;
    self->f11C = 0;
    self->f120 = 0;
    func_0057CD90(sub, 0, 0x100);
    func_0057CE40(sub, 0);
    sub->fC = 1;
    Str t;
    Str *pt = &t;
    const char *lit = D_0069B8C0;
    {
        Rep *d = &D_00659FA8;
        char *p;
        if (d->sel != 0) {
            p = func_005C2560(d);
        } else {
            p = (char *)d + 0x10;
            d->ref++;
        }
        pt->p = (s32)p;
    }
    func_005C2630(pt, 0, (u32)-1, lit, func_0057F260(lit));
    if (&t != ps) {
        release(ps);
        s32 p = t.p;
        Rep *r = (Rep *)(p - 0x10);
        s32 d = p;
        if (r->sel != 0) {
            d = (s32)func_005C2560(r);
        } else {
            r->ref++;
        }
        ps->p = d;
    }
    release(&t);
    func_00265F10(self, 1);
    func_00268450(self, 3);
}
