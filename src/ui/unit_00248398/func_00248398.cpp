/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };

struct A {
    char pad0[0x10];
    Str s;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    char v40[0x10];
    s32 f50;
};

extern "C" void *func_002030E8(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

extern "C" A *func_00248398(A *self, A *src) {
    Str *dst = &self->s;
    Str *s = &src->s;
    func_002030E8(self, src);
    if (s != dst) {
        {
            Rep *q = (Rep *)(*(s32 *)&dst->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            s32 p = *(s32 *)&s->p;
            Rep *r = (Rep *)(p - 0x10);
            s32 d = p;
            if (r->sel != 0) {
                d = (s32)func_005C2560(r);
            } else {
                r->ref++;
            }
            *(s32 *)&dst->p = d;
        }
    }
    self->f14 = src->f14;
    self->f18 = src->f18;
    self->f1C = src->f1C;
    self->f20 = src->f20;
    self->f24 = src->f24;
    self->f28 = src->f28;
    self->f2C = src->f2C;
    self->f30 = src->f30;
    self->f34 = src->f34;
    self->f38 = src->f38;
    self->f3C = src->f3C;
    func_002030E8(self->v40, src->v40);
    self->f50 = src->f50;
    return self;
}
