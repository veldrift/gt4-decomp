/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEnt { s16 delta; s16 pad; void (*fn)(void *, ...); };
struct VT { char pad[0x190]; VEnt e190; char pad2[0x18 - 8 + 0x8]; VEnt e1b0; char pad3[0x10]; VEnt e1c8; };
struct M { char pad[4]; VT *vt; char pad2[0x90]; s32 f98; };
struct Sub { char pad[4]; s32 f4; };
struct Obj {
    char pad[0xA0];
    Sub sub;
    char pad2[0x2A4 - 0xA0 - 8];
    M *m;
    void *h;
    char pad3[0x2B8 - 0x2A8 - 4];
    const char *f2b8;
};
extern Rep D_00659FA8;
extern char D_0068EE18[];
extern "C" {
void func_0013BD50(void *, void *);
void func_0013BD68(void *, int);
void func_00148080(void *, const char *);
s32 func_00145AB8(void *);
const char *func_00145E30(void *);
int func_00147D80(void *);
void func_00153B50(void *, void *);
void func_00326798(void *, s32, s32, const char *);
void func_003285A8(void *);
void func_003285F8(void *);
s32 func_00441248(s32);
s32 SPEC_DATABASE__CarEquipments__getVariationOrder(s32);
s32 func_0057F260(const char *) throw();
struct S00659988 *func_005C11A8(void);
char *func_005C2560(void *);
void *func_005C2630(void *, u32, u32, const char *, u32);

static inline const char *c_str(Str *s) {
    if (((Rep *)s->p - 1)->len == 0) return D_0068EE18;
    s->p[((Rep *)s->p - 1)->len] = 0;
    return s->p;
}
void func_0013A730(Obj *arg0, Str *arg1) {
    union { void *h[4]; Str st; } tmp;
    arg0->f2b8 = c_str(arg1);
    void **ph = &arg0->h;
    func_00148080(tmp.h, c_str(arg1));
    if (ph != tmp.h) {
        void *p = tmp.h[0];
        if (p != 0) func_003285A8(p);
        if (*ph != 0) func_003285F8(*ph);
        *ph = p;
    }
    func_0013BD68(tmp.h, 2);
    M **pm = &arg0->m;
    if (__builtin_expect((int)*pm, 0)) {
        (*pm)->f98 = 1;
        Sub *sub = &arg0->sub;
        M *m = *pm;
        VEnt *e = &m->vt->e1b0;
        e->fn((char *)m + e->delta, 0);
        const char *name = func_00145E30(*ph);
        func_00153B50(*pm, sub);
        func_0013BD50(tmp.h, ph);
        M *m2 = *pm;
        VEnt *e2 = &m2->vt->e1c8;
        e2->fn((char *)m2 + e2->delta, tmp.h);
        M *m3 = *pm;
        Str *ps = &tmp.st;
        VEnt *e3 = &m3->vt->e190;
        char *self3 = (char *)m3 + e3->delta;
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, name, func_0057F260(name));
        e3->fn(self3, &tmp.st, ph, sub->f4 == 2);
        Rep *q = (Rep *)tmp.st.p - 1;
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
}
}
