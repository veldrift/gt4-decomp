/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[12]; };
struct Inner { char pad[32]; s32 mode; };
struct Handle { Inner *p; char pad[12]; };
struct VEntry { short delta, index; Str (*fn)(void *); };
struct VObj { char pad[4]; VEntry *vtbl; };
extern Rep D_00659FA8;
extern char D_0069AE88[], D_0069AE90[], D_0069AE98[], D_0069AEA0[];
extern "C" void func_00289700(void *, void *) throw();
extern "C" void func_002896A8(void *, int) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, int, int, const char *, int);
extern "C" S00659988 *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 16);
    if (--q->ref == 0) {
        s32 size = q->cap + 16;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
extern "C" void MCrossTransition__get_type(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Handle buf;

    func_00289700(&buf, arg1);
    if (arg2 > 0) {
        VObj *o = *arg3;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
        Str t = e->fn((char *)o + e->delta);
        Str *pt = &t;
        s32 len = *(s32 *)(pt->p - 16);
        const char *c;
        if (len == 0) c = D_0069AE88;
        else { pt->p[len] = 0; c = pt->p; }
        release(&t);
        if (func_0057F238(c, D_0069AE90) == 0) buf.p->mode = 0;
        else if (func_0057F238(c, D_0069AE98) == 0) buf.p->mode = 1;
    } else {
        Handle h;
        Str s;
        const char *src = D_0069AEA0;
        switch (buf.p->mode) {
        case 0: src = D_0069AE90; break;
        case 1: src = D_0069AE98; break;
        }
        Str *ps = &s;
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) d = func_005C2560(r);
        else { d = (char *)(r + 1); r->ref++; }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        Handle *ph = &h;
        func_00314B20(ph, ps);
        if ((void *)arg0 != (void *)ph) {
            s32 newVal = (s32)ph->p;
            if (newVal) func_003285A8(newVal);
            s32 oldVal = *arg0;
            if (oldVal) func_003285F8(oldVal);
            *arg0 = newVal;
        }
        func_00312318(ph, 2);
        release(ps);
    }
    func_002896A8(&buf, 2);
}
