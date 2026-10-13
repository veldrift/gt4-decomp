typedef int s32;

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

struct S00659988 {
    const char *name;
};

extern "C" void func_002106E0(void *, s32 *);
extern "C" void func_00210710(void *, s32);
extern "C" void func_00265F48(char *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00295FD8(char *arg0, Str *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    Str *s2 = (Str *)(arg0 + 0xF8);
    s32 *dst;
    s32 newVal;
    s32 oldVal;

    if (arg1 != s2) {
        str_release(s2);
        {
            char *d = arg1->p;
            Rep *r = (Rep *)(d - 0x10);
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                r->ref++;
            }
            s2->p = d;
        }
    }
    buf1[0] = 0;
    dst = (s32 *)(arg0 + 0x118);
    func_002106E0(buf0, buf1);
    if (dst != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
    func_00210710(buf0, 2);
    func_00265F48(arg0, 0);
}
