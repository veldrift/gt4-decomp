typedef int s32;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
extern Rep D_00659FA8;
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(s32);
extern "C" void func_005C2630(void *, s32, s32, s32, s32);
extern "C" S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_0023A538(void *, s32, s32, void *, void *);
extern "C" void func_002319A0(s32, void *);
extern "C" void func_00239F08(void *, s32);
extern "C" void func_002ED5C0(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00122B78(char *arg0, s32 arg1) {
    char sp0[0x30];
    Str s;
    char sp40[0x10];
    s32 a, b;
    func_00576100(arg0 + 0x10);
    a = *(s32 *)(arg0 + 0x84);
    b = *(s32 *)(arg0 + 0x88);
    func_00576140(arg0 + 0x10);
    if (a != 0 && b != 0) {
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
        func_005C2630(ps, 0, -1, arg1, func_0057F260(arg1));
        func_002EFBF0(sp40);
        func_0023A538(sp0, a, b, ps, sp40);
        func_002319A0(a, sp0);
        func_00239F08(sp0, 2);
        func_002ED5C0(sp40, 2);
        str_release(ps);
    }
}
