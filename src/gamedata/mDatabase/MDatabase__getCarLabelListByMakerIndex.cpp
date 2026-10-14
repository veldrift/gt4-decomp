/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, s32, void *);
extern "C" s32 func_002EFBF0(void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_00448528(void);
extern "C" void func_00448540(s32, void *, s32);
extern "C" s32 func_00448738(void *, s32 *, s32 *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void MDatabase__getCarLabelListByMakerIndex(s32 *arg0, void *arg1, void *arg2) {
    s32 sp0[4];
    char buf[0x100];
    s32 v110, v114;
    s32 r120[4], r130[4], r140[4];
    s32 v150;
    s32 i;
    s32 n;
    i = 0;
    func_002FC8C8(sp0, arg2);
    v150 = func_002FE250(sp0[0]);
    func_002FC870(sp0, 2);
    n = func_00448528();
    func_002EFBF0(sp0);
    if (n > 0) {
        char *b = buf;
        s32 *p130 = r130;
        do {
            func_00448540(i, buf, 0x100);
            func_00448738(buf, &v110, &v114);
            if (v110 == v150) {
                s32 *p140 = r140;
                s32 *p120 = r120;
                s32 s1 = sp0[0];
                {
                    Rep *d = &D_00659FA8;
                    char *p;
                    if (d->sel != 0) {
                        p = func_005C2560(d);
                    } else {
                        p = (char *)d + 0x10;
                        d->ref++;
                    }
                    p140[0] = (s32)p;
                }
                func_005C2630(p140, 0, (u32)-1, b, func_0057F260(b));
                func_00314B20(p130, p140);
                func_002EEEB0(p120, s1, p130);
                func_00309378(p120, 2);
                func_00312318(p130, 2);
                {
                    Rep *q = (Rep *)(p140[0] - 0x10);
                    if (--q->ref == 0) {
                        s32 cap = q->cap + 0x10;
                        func_00326798(q, cap, 4, func_005C11A8()->name);
                    }
                }
            }
            i++;
        } while (i < n);
    }
    if (arg0 != sp0) {
        s32 nv = sp0[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_002ED5C0(sp0, 2);
}
