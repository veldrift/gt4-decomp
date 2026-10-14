typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct Obj { char pad[0x1CC]; s32 f1CC; char name[1]; };

extern Rep D_00659FA8;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, s32, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MNetwork__imGetUser(s32 *arg0, s32 arg1) {
    s32 buf0[4];
    Obj *buf10[4];
    Str s20;
    s32 buf30[4];
    s32 buf40[4];
    s32 buf50[4];
    Obj **p_s5;
    Str *p_s4;
    s32 *p_s2;
    s32 *p_s0;
    s32 *p_s0b;
    const char *nm;
    s32 h;
    s32 h2;
    s32 newVal;
    s32 oldVal;
    func_002EFBF0(buf0);
    p_s5 = buf10;
    func_001DC650(p_s5, arg1);
    nm = (*p_s5)->name;
    p_s4 = &s20;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s4->p = d;
    }
    func_005C2630(p_s4, 0, -1, nm, func_0057F260(nm));
    h = buf0[0];
    p_s0 = buf40;
    p_s2 = buf30;
    func_002FE278(p_s0, (*p_s5)->f1CC);
    func_002EEEB0(p_s2, h, p_s0);
    func_00309378(p_s2, 2);
    func_002FC870(p_s0, 2);
    p_s0b = buf50;
    h2 = buf0[0];
    func_00314B20(p_s0b, p_s4);
    func_002EEEB0(p_s2, h2, p_s0b);
    func_00309378(p_s2, 2);
    func_00312318(p_s0b, 2);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    str_release(p_s4);
    func_001DC5F8(p_s5, 2);
    func_002ED5C0(buf0, 2);
}
