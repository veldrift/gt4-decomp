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

struct SS {
    char *p;
    s32 pad[3];
};

struct Str {
    char *p;
};

struct VCall { short delta, index; void *(*fn)(void *); };
struct VCall2 { short delta, index; s32 (*fn)(void *); };
struct Obj {
    char pad0[4];
    char *vt;
};

extern char D_0069DE58[];
extern char D_0069DE60[];
extern char D_0069DE68[];
extern char D_0069DE70[];
extern char D_0069DE78[];

extern "C" void func_0032B5C0(SS *arg0);
extern "C" void *func_0032B6D8(void *arg0, s32 arg1);
extern "C" void *func_0032B808(void *arg0, const char *arg1);
extern "C" void *func_0032B860(void *arg0, void *arg1);
extern "C" Str *func_0032B8C0(SS *arg0);
extern "C" const char *hModule__getName(void *arg0);
extern "C" s32 func_003284E8(void *arg0);
extern "C" char *func_005C2560(Rep *src);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" Str *hObject__toString(Str *arg0, Obj *arg1) {
    SS ss;
    func_0032B5C0(&ss);
    void *s0 = func_0032B808(&ss, D_0069DE58);
    VCall *g = (VCall *)(arg1->vt + 0x50);
    void *s1 = func_0032B808(s0, hModule__getName(g->fn((char *)arg1 + g->delta)));
    void *s2 = func_0032B808(func_0032B860(func_0032B808(s1, D_0069DE60), arg1), D_0069DE68);
    void *s3 = func_0032B808(func_0032B6D8(s2, func_003284E8(arg1)), D_0069DE70);
    VCall2 *h = (VCall2 *)(arg1->vt + 0x40);
    func_0032B808(func_0032B6D8(s3, h->fn((char *)arg1 + h->delta)), D_0069DE78);
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
