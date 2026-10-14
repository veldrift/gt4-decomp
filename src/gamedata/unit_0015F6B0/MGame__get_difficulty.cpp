/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct Str2 { char *p; int pad[7]; };
struct Q { char pad[0x10]; char *f10; };
struct H { Q *p; s32 pad[3]; };
struct VEntryB { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern Rep D_00659FA8;
extern char D_006901F0[];
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0015F388(void *, int) throw();
extern "C" int func_0015F3E0(void *) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" const char *func_00430270(s32);
extern "C" s32 func_00430298(const char *);

extern "C" void MGame__get_difficulty(s32 *out, s32 unused, s32 n, Obj **arg3) {
    H h;
    Str2 s10;
    if (n > 0) {
        func_0015F3E0(&h);
        Obj *o = *arg3;
        Str *ps = (Str *)&s10;
        char *t = h.p->f10 + 4;
        VEntryB *e = (VEntryB *)(o->vtbl + 0x18);
        e->fn(ps, (char *)o + e->delta);
        const char *cs;
        s32 len = ((Rep *)ps->p - 1)->len;
        if (len == 0) {
            cs = D_006901F0;
        } else {
            ps->p[len] = 0;
            cs = ps->p;
        }
        *(s32 *)(t + 0xC8) = func_00430298(cs);
        {
            Rep *q = (Rep *)ps->p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_0015F388(&h, 2);
    } else {
        Str s30;
        H h40;
        Str *ps = &s30;
        H *ph = &h40;
        func_0015F3E0(ph);
        const char *res = func_00430270(*(s32 *)(ph->p->f10 + 0xCC));
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, res, func_0057F260(res));
        func_00314B20(&h, ps);
        if (out != (s32 *)&h) {
            s32 nv = (s32)h.p;
            if (nv) func_003285A8(nv);
            if (*out) func_003285F8(*out);
            *out = nv;
        }
        func_00312318(&h, 2);
        {
            Rep *q = (Rep *)ps->p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_0015F388(ph, 2);
    }
}
