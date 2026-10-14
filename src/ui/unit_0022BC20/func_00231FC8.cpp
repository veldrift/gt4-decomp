typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };
extern char D_00659FA8[];
extern "C" void func_00232C20(void *, s32) throw();
extern "C" int func_002330F8(void *) throw();
extern "C" void func_003069F8(s32, void *, void *);
extern "C" s32 HSymID__GetID(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005C2630(Str *, s32, s32, const char *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" s32 func_00231FC8(char *self, const char *name) {
    s32 *pv = (s32 *)(self + 0x1D04);
    if (*pv == 0) return 0;
    s32 buf0[4];
    s32 buf1[4];
    Str s;
    func_002330F8(buf0);
    s32 obj = *pv;
    Str *ps = &s;
    Rep *r = (Rep *)D_00659FA8;
    char *d;
    s32 *pb = buf1;
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        r->ref++;
        d = (char *)(r + 1);
    }
    ps->p = d;
    func_005C2630(ps, 0, -1, name, func_0057F260(name));
    pb[0] = HSymID__GetID(ps);
    func_003069F8(obj, buf0, pb);
    str_release(ps);
    s32 h = buf0[0];
    func_00232C20(buf0, 2);
    return h;
}
