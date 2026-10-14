/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct VEntryA { short delta; short index; struct Obj **(*fn)(void *, s32); };
struct VEntryB { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern char D_0069D598[];
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0057F238(const char *, const char *) throw();

extern "C" s32 func_002EFFD0(Obj *self, const char *key, s32 lo, s32 hi) {
    if (lo == hi) return -1;
    Str s;
    s32 mid = (hi - lo) / 2 + lo;
    VEntryA *e = (VEntryA *)(self->vtbl + 0x70);
    Obj **o = e->fn((char *)self + e->delta, mid);
    Obj *oo = *o;
    VEntryB *e2 = (VEntryB *)(oo->vtbl + 0x18);
    e2->fn(&s, (char *)oo + e2->delta);
    const char *cs;
    s32 len = ((Rep *)s.p - 1)->len;
    if (len == 0) {
        cs = D_0069D598;
    } else {
        s.p[len] = 0;
        cs = s.p;
    }
    s32 c = func_0057F238(key, cs);
    {
        Rep *q = (Rep *)s.p - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    if (c == 0) return mid;
    if (c < 0) return func_002EFFD0(self, key, lo, mid);
    return func_002EFFD0(self, key, mid + 1, hi);
}
