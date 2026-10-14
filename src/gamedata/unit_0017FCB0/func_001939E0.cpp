/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Obj16 {
    char pad[0x10];
};

extern Rep D_00659FA8;
extern char D_00692208[];

extern "C" void func_00239F08(void *, int);
extern "C" void func_0023A538(void *, void *, void *, void *, void *);
extern "C" void func_00250CE0(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void func_001939E0(void *arg0, void *arg1, void *arg2) {
    char res[0x30];
    Str s;
    Obj16 h;
    Str *ps = &s;
    const char *src = D_00692208;
    {
        Rep *r = &D_00659FA8;
        char *d = (char *)(r + 1);
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        ps->p = d;
    }
    func_005C2630(ps, 0, -1, src, func_0057F260(src));
    func_002EFBF0(&h);
    func_0023A538(res, arg2, arg0, ps, &h);
    func_00250CE0(arg1, res);
    func_00239F08(res, 2);
    func_002ED5C0(&h, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
}
