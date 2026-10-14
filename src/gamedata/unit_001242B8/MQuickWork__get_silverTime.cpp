/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
struct B12 { char c[12]; };
extern B12 D_0068DEB0;
extern "C" void func_001240D8(void *, int) throw();
extern "C" s32 func_00124130(void *, void *) throw();
extern "C" void func_00127AF0(s32, s32, void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *, int, u32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void MQuickWork__get_silverTime(s32 *arg0, void *arg1) {
    s32 obj[4];
    struct L { B12 b; s32 zero[0x1D]; } l;
    s32 s90[4];
    s32 sA0[4];
    func_00124130(obj, arg1);
    char *buf = l.b.c;
    l.b = D_0068DEB0;
    func_005A48D8(l.zero, 0, 0x74);
    func_00127AF0(obj[0], 1, buf, 0x80);
    s32 *pA0 = sA0;
    {
        Rep *d = &D_00659FA8;
        char *p;
        if (d->sel != 0) {
            p = func_005C2560(d);
        } else {
            p = (char *)d + 0x10;
            d->ref++;
        }
        pA0[0] = (s32)p;
    }
    func_005C2630(pA0, 0, (u32)-1, buf, func_0057F260(buf));
    s32 *p90 = s90;
    func_00314B20(p90, pA0);
    if (arg0 != p90) {
        s32 nv = p90[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_00312318(p90, 2);
    {
        Rep *q = (Rep *)(pA0[0] - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_001240D8(obj, 2);
}
