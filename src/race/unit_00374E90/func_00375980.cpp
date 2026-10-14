/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
struct Entry { short delta, index; int (*fn)(void *, int); };
struct Entry0 { short delta, index; int (*fn)(void *); };
struct EntryF { short delta, index; float (*fn)(void *); };
struct Entry6 { short delta, index; void (*fn)(void *, char *, int, int, int, int, float); };
struct Obj { char *vtbl; };
struct Tgt { char *vtbl; char pad[0x164]; u64 u168; };
struct Cursor { int a, b, c, d; };
struct Out { int a, b; float c; };
extern "C" void func_00378F28(Tgt *, char *, char *, char *, char *);
extern "C" int func_003FDAB8(char *, int, Cursor *, int);
static inline Tgt *VCALL(Obj *self, int idx) {
    Entry *e = (Entry *)(self->vtbl + 0xD8);
    return (Tgt *)e->fn((char *)self + e->delta, idx);
}
extern "C" void func_00375980(Obj *self, char *ctx, int a2, int idx, unsigned flags, Out *out) {
    Cursor cur;
    char *base = (char *)self + idx * 0x19C;
    char *s1 = base + 0x10;
    char *s7 = base + 0xE0;
    char *fp = (char *)self + 0x9C0;
    func_00378F28(VCALL(self, idx), ctx, s7, s1, fp);
    if (*(int *)(s1 + 0x130) >= 0) {
        Tgt *p = VCALL(self, idx);
        Entry0 *e = (Entry0 *)(p->vtbl + 0xA0);
        if ((e->fn((char *)p + e->delta) ^ 3) == 0) {
            Tgt *t = *(Tgt **)(s1 + 0x14C);
            int next = *(int *)(s1 + 0x130) + 1;
            if (func_003FDAB8(ctx, next, &cur, 1)) next = 0;
            int found = cur.c;
            if (found != 0) {
                p = VCALL(self, idx);
                EntryF *ef = (EntryF *)(p->vtbl + 0xC8);
                out->c = ef->fn((char *)p + ef->delta);
                out->a = 1;
                *(Tgt **)(s1 + 0x12C) = t;
                Entry6 *e6 = (Entry6 *)(t->vtbl + 0x138);
                e6->fn((char *)t + e6->delta, s1, *(int *)(ctx + 0x80), cur.b, found, 1, 1.0f);
                t->u168 = (t->u168 & 0xFFFF00FFFFFFFFFFul) | 0x10000000000ul;
                func_00378F28(t, ctx, s7, s1, fp);
                *(int *)(s1 + 0x130) = next;
            } else {
                *(int *)(s1 + 0x130) = -2;
            }
        }
    }
}
