/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };

struct Inner;
struct VEnt {
    short adj;
    short pad;
    void (*fn)(Str *, Inner *);
};
struct VTab {
    char pad[0x18];
    VEnt e;
};
struct Inner {
    s32 pad0;
    VTab *vt;
};

struct Node {
    char pad0[0x10];
    s32 v10;
    char pad14[0xC4 - 0x14];
    Str s;
};

extern "C" Str D_00836448;
extern "C" void func_0029C658(Node *) throw();
extern "C" s32 func_00314AD8(Inner *);
extern "C" s32 func_0055F420(s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

static inline void assign(Str *dst, Str *src) {
    if (src != dst) {
        release(dst);
        char *p = src->p;
        Rep *r = (Rep *)(p - 0x10);
        char *d = p;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref = r->ref + 1;
        }
        dst->p = d;
    }
}

extern "C" void func_0029C7F8(Node *self, Inner **pin) {
    self->v10 = func_0055F420(func_00314AD8(*pin));
    if (self->v10 != 0) {
        Inner *x = *pin;
        VEnt *e = &x->vt->e;
        Str t;
        e->fn(&t, (Inner *)((char *)x + e->adj));
        assign(&self->s, &t);
        release(&t);
    } else {
        assign(&self->s, &D_00836448);
    }
    func_0029C658(self);
}
