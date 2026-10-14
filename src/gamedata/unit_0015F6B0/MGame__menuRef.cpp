/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct H { struct Q *p; s32 pad[7]; };
struct Q { char pad[0x10]; s32 f10; };
struct VEntryA { short delta; short index; s32 (*fn)(void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0015F388(void *, int) throw();
extern "C" void func_0015F3E0(void *, void *) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" const char *func_0042FDF0(s32, const char *);

extern "C" void MGame__menuRef(s32 *out, void *arg1, s32 n, Obj **arg3) {
    const char *key = 0;
    if (n > 0) {
        Obj *o = *arg3;
        VEntryA *e = (VEntryA *)(o->vtbl + 0x58);
        key = (const char *)e->fn((char *)o + e->delta);
    }
    H h;
    func_0015F3E0(&h, arg1);
    const char *res = func_0042FDF0(h.p->f10 + 0x3A368, key);
    func_0015F388(&h, 2);
    if (res) {
        Str s;
        Str *ps = &s;
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
    }
}
