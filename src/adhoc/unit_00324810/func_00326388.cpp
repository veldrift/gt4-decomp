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

struct SS {
    char *p;
    s32 pad[3];
};

struct Str {
    char *p;
};

extern char D_0069E8C8[];
extern char D_0069E8D0[];
extern char D_0069E8D8[];
extern char D_0069E8E0[];
extern char D_0069E8E8[];
extern char D_0069E900[];
extern char D_0069E908[];

extern "C" void func_0032B5C0(SS *arg0);
extern "C" void *func_0032B738(void *arg0, s32 arg1);
extern "C" void **func_0032B808(void *arg0, const char *arg1);
extern "C" void *func_0032B658(void *arg0, const void *arg1);
extern "C" Str *func_0032B8C0(SS *arg0);
extern "C" char *func_005C2560(Rep *src);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" Str *func_00326388(Str *arg0, const char *arg1, const char *arg2, s32 arg3,
                              const char *arg4, const void *arg5) {
    SS ss;
    char buf[0x80];
    const char *s0 = D_0069E8C8;
    func_0032B5C0(&ss);
    char *pb = buf;
    func_0032B808(func_0032B658(func_0032B808(func_0032B808(func_0032B808(func_0032B738(
        func_0032B808(func_0032B808(&ss, pb), s0), -1), D_0069E8D0), arg1), D_0069E8D8), arg5),
        D_0069E8E0);
    func_0032B808(func_0032B808(func_0032B808(func_0032B738(func_0032B808(func_0032B808(
        func_0032B808(func_0032B738(func_0032B808(func_0032B808(&ss, pb), s0), -1),
        D_0069E8E8), arg2), s0), arg3), D_0069E900), arg4), D_0069E908);
    {
        s32 p = *(s32 *)&func_0032B8C0(&ss)->p;
        Rep *r = (Rep *)(p - 0x10);
        s32 d = p;
        if (r->sel != 0) {
            d = (s32)func_005C2560(r);
        } else {
            r->ref++;
        }
        *(s32 *)&arg0->p = d;
    }
    {
        Rep *q = (Rep *)(*(s32 *)&ss.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return arg0;
}
