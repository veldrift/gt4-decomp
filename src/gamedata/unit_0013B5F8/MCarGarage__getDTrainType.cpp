/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
extern Rep D_00659FA8;
extern char D_0068EE70[];
extern "C" {
void func_0013BD68(void *, int) throw();
void func_0013BDC0(void *, void *) throw();
s32 func_00145EF0(void *);
void func_00312318(void *, int);
void func_00314B20(void *, void *);
void func_00326798(void *, s32, s32, const char *);
void func_003285A8(void *);
void func_003285F8(void *);
s32 func_0057F260(const char *) throw();
struct S00659988 *func_005C11A8(void);
char *func_005C2560(void *);
void *func_005C2630(void *, u32, u32, const char *, u32);

void MCarGarage__getDTrainType(void **arg0, void *arg1) {
    void *h[8];
    const char *s;
    Str st;
    func_0013BDC0(h, arg1);
    s = (const char *)func_00145EF0(h[0]);
    func_0013BD68(h, 2);
    if (s == 0) s = D_0068EE70;
    char *d;
    Str *ps = &st;
    if (D_00659FA8.sel != 0) {
        d = func_005C2560(&D_00659FA8);
    } else {
        d = (char *)(&D_00659FA8 + 1);
        D_00659FA8.ref++;
    }
    ps->p = d;
    func_005C2630(ps, 0, -1, s, func_0057F260(s));
    func_00314B20(h, ps);
    if (arg0 != h) {
        void *p = h[0];
        if (p != 0) func_003285A8(p);
        if (*arg0 != 0) func_003285F8(*arg0);
        *arg0 = p;
    }
    func_00312318(h, 2);
    Rep *q = (Rep *)ps->p - 1;
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
}
