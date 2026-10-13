typedef int s32;
typedef unsigned int size_t;

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

extern Rep D_00659FA8;
extern char D_00697800[];

extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0020EEA0(s32, Str *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" s32 func_005A2F88(char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" s32 func_0020E770(s32 arg0, s32 *arg1) {
    Str s;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s.p = d;
    }
    s32 rc = func_0020EEA0(arg0, &s);
    if (rc != 0x101) {
        str_release(&s);
        return 0;
    }
    {
        char *dat = s.p;
        s32 len = ((Rep *)(dat - 0x10))->len;
        char *a;
        if (len == 0) {
            a = D_00697800;
        } else {
            *(dat + len) = 0;
            a = s.p;
        }
        *arg1 = func_005A2F88(a);
    }
    str_release(&s);
    return 1;
}
