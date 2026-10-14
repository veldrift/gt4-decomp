/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct VEnt { s16 delta; s16 idx; void (*fn)(void *, void *); };
struct VT { char pad[0x18]; VEnt e; };
struct Obj { char pad[4]; VT *vt; };
extern char D_00697980[];

extern Rep D_00659FA8;
extern "C" void func_00211408(void *, s32) throw();
extern "C" void func_00211460(void *, s32) throw();
extern "C" int MWidgetReader__structor_1(s32, void *, void *, void *);
extern "C" s32 func_00255088(void *, void *);
extern "C" void func_002550B8(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005C2630(void *, s32, s32, const char *, s32);

static inline void setp(char **d, char *p) { *d = p; }
static inline s32 first(s32 *p) { return *p; }
static inline void str_release(char **pp) {
    Rep *q = (Rep *)(*pp - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MManager__loadWidget(s32 *arg0, s32 arg1, s32 arg2, Obj **arg3) {
    s32 o[4];
    s32 a[4];
    s32 b[4];
    char *s[4];
    s32 z;
    z = 0;
    func_00255088(o, &z);
    if (arg2 == 1) {
        func_00211460(a, arg1);
        s32 s4 = first(a);
        Obj *a2 = *arg3;
        VEnt *e = &a2->vt->e;
        e->fn(b, (char *)a2 + e->delta);
        const char *str = D_00697980;
        char **ps = s;
        char *p;
        if (D_00659FA8.sel != 0) {
            p = func_005C2560(&D_00659FA8);
        } else {
            p = (char *)&D_00659FA8 + 0x10;
            D_00659FA8.ref = D_00659FA8.ref + 1;
        }
        setp(ps, p);
        func_005C2630(ps, 0, -1, str, func_0057F260(str));
        MWidgetReader__structor_1(s4, o, b, s);
        str_release(s);
        str_release((char **)b);
        func_00211408(a, 2);
    }
    if (arg0 != o) {
        s32 v = o[0];
        if (v != 0) func_003285A8(v);
        s32 old = *arg0;
        if (old != 0) func_003285F8(old);
        *arg0 = v;
    }
    func_002550B8(o, 2);
}
