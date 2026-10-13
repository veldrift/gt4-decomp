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

struct Reader {
    char pad0[0xC];
    s32 p;
};

struct Obj;

extern "C" s32 func_0024DB78(Obj *arg0, Reader *arg1);
extern "C" s32 func_005C2A50(Str *self, Str *other, u32 pos, u32 n);
extern "C" char *func_005C2560(Rep *src);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" s32 func_0020FD38(Reader *arg0, Str *arg1, Obj *arg2) {
    Str s;
    s32 d;
    {
        s32 p = arg0->p;
        Rep *r = (Rep *)(p - 0x10);
        d = p;
        if (r->sel != 0) {
            d = (s32)func_005C2560(r);
        } else {
            r->ref++;
        }
    }
    s.p = (char *)d;
    s32 found = func_005C2A50(arg1, &s, 0, -1) == 0;
    str_release(&s);
    if (found) {
        func_0024DB78(arg2, arg0);
        return 1;
    }
    return 0;
}
