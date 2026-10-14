typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct RefCounter;
struct Holder { char pad[0x30]; char *str; };

extern "C" void func_00208F18(void *, s32) throw();
extern "C" void *func_00208F70(void *, s32) throw();
extern "C" void func_00312318(void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

extern "C" void MDomNode__get_value(s32 *dst, s32 a1) {
    struct F { s32 h[4]; char *s[4]; s32 pad[4]; Holder *obj[4]; } fr;
    Holder **po = &fr.obj[0];
    func_00208F70(po, a1);
    char *d = (*po)->str;
    char **ps = &fr.s[0];
    Rep *r = (Rep *)(d - 0x10);
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        r->ref++;
    }
    *ps = d;
    func_00314B20(fr.h, ps);
    if (dst != fr.h) {
        s32 n = fr.h[0];
        if (n != 0)
            func_003285A8((RefCounter *)n);
        s32 old = *dst;
        if (old != 0)
            func_003285F8((RefCounter *)old);
        *dst = n;
    }
    func_00312318(fr.h, 2);
    Rep *q = (Rep *)(*ps - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
    func_00208F18(po, 2);
}
