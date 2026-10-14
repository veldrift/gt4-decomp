/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct O {
    char padB0[0xB0]; int iB0;
    char pad1[0x124 - 0xB4];
    int i124; int i128; char *strs[128]; signed char tab[0x80];
    int i3AC; int i3B0; int i3B4; int i3B8; int i3BC; int i3C0; int i3C4;
};
extern Rep D_00659FA8;
extern "C" s32 func_00265E40();
extern "C" void func_00265E50(void *, s32);
extern "C" void func_00265FB8(void *, int);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

static inline void str_release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
static inline char *str_copy(Rep *r) {
    char *d;
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        d = (char *)(r + 1);
        r->ref = r->ref + 1;
    }
    return d;
}

extern "C" void func_002E54F0(O *o)
{
    char *sp0;
    char **p = &o->strs[0];
    int n = 0x7F;
    s32 s7 = func_00265E40();
    func_00265E50(o, 0);
    char *v = (char *)o + 0xC0;
    o->i124 = 0;
    o->i128 = 0;
    o->i3AC = 0;
    o->i3B0 = 0;
    o->i3B4 = 0;
    o->i3B8 = 1;
    o->i3BC = 0;
    o->i3C0 = 0;
    o->i3C4 = 0;
    *(int *)(v + 0x20) = 0;
    *(int *)(v + 0x24) = 0;
    *(int *)(v + 0x18) = 1;
    o->iB0 = 1;
    func_00265FB8(o, 1);
    char **tmp = &sp0;
    do {
        *tmp = str_copy(&D_00659FA8);
        if (&sp0 != p) {
            str_release(*p);
            char *d = sp0;
            Rep *r = (Rep *)(d - 0x10);
            if (r->sel != 0) d = func_005C2560(r);
            else r->ref = r->ref + 1;
            *p = d;
        }
        str_release(sp0);
        n--;
        p++;
    } while (n >= 0);
    func_00265E50(o, s7);
}
