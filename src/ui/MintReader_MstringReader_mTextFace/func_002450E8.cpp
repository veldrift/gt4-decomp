typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Obj {
    char pad[0x104];
    void *p104;
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;
extern char D_00699138[];
extern char D_00699158[];

extern "C" void func_002B7118(void *self, void **src);
extern "C" s32 func_0025A7E0(void *a0, void *a1);
extern "C" s32 func_0026A4D0(void *a0, void **a1);
extern "C" void func_0026A118(void *a0, s32 a1);
extern "C" void func_00245270(void *a0, void *a1);
extern "C" char *func_005C2560(Rep *src);
extern "C" s32 func_0057F260(s32 s);
extern "C" void *func_005C2630(void *str, s32 pos, s32 n1, s32 s, s32 n2);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 n, s32 align, const char *name);
extern "C" void func_005DB110(const char *fmt, ...);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_002450E8(Obj *arg0, void **arg1) {
    Str tmp;
    Str *ps;
    s32 s1;

    func_002B7118(arg0->p104, arg1);
    if (*(s32 *)((char *)*arg1 - 0x10) != 0) {
        func_0025A7E0(&tmp, arg0);
        s1 = func_0026A4D0(tmp.p, arg1);
        func_0026A118(&tmp, 2);
        if (s1 != 0) {
            Rep *r;
            char *d;
            ps = &tmp;
            r = &D_00659FA8;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005C2630(ps, 0, -1, s1, func_0057F260(s1));
            func_00245270(arg0, &tmp);
            str_release(&tmp);
        } else {
            char *p = (char *)*arg1;
            s32 len = *(s32 *)(p - 0x10);
            char *a;
            if (len == 0) {
                a = D_00699158;
            } else {
                p[len] = 0;
                a = (char *)*arg1;
            }
            func_005DB110(D_00699138, a);
        }
    }
}
