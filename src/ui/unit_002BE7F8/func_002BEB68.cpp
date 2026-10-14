typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct Self {
    char pad0[0x2D8];
    Str s;
    s32 h;
};

extern "C" void func_0021B340(void *, int);
extern "C" void func_0025A7E0(s32 *, Self *);
extern "C" s32 func_0026A118(void *, int);
extern "C" void func_0026AC20(s32 *, s32, Str *, s32, s32, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

static inline bool empty(Str *s) { return ((Rep *)(s->p - 0x10))->len == 0; }

extern "C" void func_002BEB68(Self *self, Str *src) {
    s32 h[4];
    s32 h2[4];
    Str *dst = &self->s;
    if (src != dst) {
        {
            Rep *q = (Rep *)(*(s32 *)&dst->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            char *d = src->p;
            Rep *r = (Rep *)(d - 0x10);
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                r->ref++;
            }
            dst->p = d;
        }
    }
    if (empty(dst)) return;
    {
        s32 *ph = h2;
        s32 *dh = &self->h;
        func_0025A7E0(ph, self);
        func_0026AC20(h, *ph, dst, 1, 0, 1);
        if (dh != h) {
            s32 nv = h[0];
            if (nv != 0) func_003285A8(nv);
            if (*dh != 0) func_003285F8(*dh);
            *dh = nv;
        }
        func_0021B340(h, 2);
        func_0026A118(ph, 2);
    }
}
