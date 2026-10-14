/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Name { const char *name; };
struct Arr { char *s[4]; };
struct Elem { s32 pad0; Arr arr; char pad14[0x10]; };
struct Vec { s32 pad0; Elem *start; Elem *finish; Elem *eos; };
struct Self { char pad0[4]; void *vt; char pad8[0x40]; Vec v; };

extern void *mOSKeyboard__vtable;
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void RefCounter__structor_2(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" Name *func_005E9730(void);

static inline void str_release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void destroy_elem(Elem *e) {
    if ((char *)e + 4 != 0) {
        char *p = (char *)e + 0x14;
        char *m = (char *)e + 4;
        while (m != p) {
            p -= 4;
            str_release(*(char **)p);
        }
    }
}

extern "C" void mOSKeyboard__structor_1(Self *self, s32 flag) {
    self->vt = &mOSKeyboard__vtable;
    Vec *v = &self->v;
    Elem *first = v->start;
    Elem *last = v->finish;
    Elem **pf = &first;
    for (Elem *e = *pf; e != last; ++e) {
        destroy_elem(e);
    }
    Elem *st = v->start;
    s32 n = v->eos - st;
    if (st != 0) {
        func_00326798(st, n * sizeof(Elem), 4, func_005E9730()->name);
    }
    RefCounter__structor_2(self, 0);
    if (flag & 1) {
        func_00326798(self, 0x68, 4, "RefCounter");
    }
}
