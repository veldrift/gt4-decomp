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
extern char D_00692228[];

extern "C" void func_00239F08(void *, int);
extern "C" void func_0023A538(void *, void *, void *, void *, void *);
extern "C" void func_00250CE0(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, void *, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void func_00193C88(void *arg0, void *arg1, void *arg2, s32 arg3) {
    struct { void *p; char pad[0xC]; } h;
    Obj16 res;
    Obj16 a;
    Str s;
    const char *src;
    Obj16 *pr;
    func_002EFBF0(&h);
    pr = &res;
    {
        Obj16 *pa = &a;
        void *hp = h.p;
        func_002FE278(pa, arg3 != 0);
        func_002EEEB0(pr, hp, pa);
        func_00309378(pr, 2);
        func_002FC870(pa, 2);
    }
    {
        Str *ps = &s;
        src = D_00692228;
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
        func_0023A538(pr, arg2, arg0, ps, &h);
        func_00250CE0(arg1, pr);
        func_00239F08(pr, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
    }
    func_002ED5C0(&h, 2);
}
