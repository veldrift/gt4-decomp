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

extern Rep D_00659FA8;

extern "C" void MstringReader__structor_6(void *arg0, Str *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *src);

extern "C" void **func_00261EC0(void **arg0, void *arg1) {
    Str s;
    Rep *r = &D_00659FA8;
    char *d = (char *)(r + 1);
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        r->ref++;
    }
    s.p = d;
    MstringReader__structor_6(arg1, &s);
    {
        s32 p = *(s32 *)&s.p;
        Rep *q = (Rep *)(p - 0x10);
        s32 e = p;
        if (q->sel != 0) {
            e = (s32)func_005C2560(q);
        } else {
            q->ref++;
        }
        *(s32 *)arg0 = e;
    }
    {
        Rep *q = (Rep *)(*(s32 *)&s.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return arg0;
}
