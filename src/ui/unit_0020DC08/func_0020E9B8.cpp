/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

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
};

extern "C" Rep D_00659FA8;
extern "C" char D_00697800[];
extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0020EEA0(void *, Str *);
extern "C" int func_005A2F70(const char *);
extern "C" float dptofp(int);

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}


extern "C" s32 func_0020E9B8(void *self, Str *out) {
    Str s;
    char *v;
    if (D_00659FA8.sel != 0) {
        v = func_005C2560(&D_00659FA8);
    } else {
        v = (char *)&D_00659FA8 + 0x10;
        D_00659FA8.ref++;
    }
    s.p = v;
    if (func_0020EEA0(self, &s) != 0x102) {
        release(&s);
        return 0;
    }
    if (&s != out) {
        release(out);
        char *p = s.p;
        Rep *r = (Rep *)(p - 0x10);
        char *d = p;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        out->p = d;
    }
    release(&s);
    return 1;
}
