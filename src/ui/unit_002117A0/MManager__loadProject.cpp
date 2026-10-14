/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct VEnt { s16 delta; s16 idx; void (*fn)(void *, void *); };
struct VEnt1 { s16 delta; s16 idx; s32 (*fn)(void *); };
struct VT { char pad[0x18]; VEnt e; };
struct VT58 { char pad[0x58]; VEnt1 e; };
struct Obj { char pad[4]; VT *vt; };
struct Obj58 { char pad[4]; VT58 *vt; };

extern "C" void func_00211408(void *, s32) throw();
extern "C" s32 func_00211460(void *, s32) throw();
extern "C" void MWidgetReader__structor_2(s32, void *, void *, s32);
extern "C" s32 func_00229270(void *, void *);
extern "C" void func_002292A0(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" S00659988 *func_005C11A8(void);

static inline s32 first(s32 *p) { return *p; }
static inline void str_release(char **pp) {
    Rep *q = (Rep *)(*pp - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MManager__loadProject(s32 *arg0, s32 arg1, s32 arg2, Obj **arg3) {
    s32 o[4];
    s32 a[4];
    s32 b[4];
    s32 z;
    z = 0;
    func_00229270(o, &z);
    if (arg2 > 0) {
        s32 s4 = 1;
        func_00211460(a, arg1);
        if (arg2 == 2) {
            Obj58 *a1 = (Obj58 *)arg3[1];
            VEnt1 *e1 = &a1->vt->e;
            s4 = e1->fn((char *)a1 + e1->delta) != 0;
        }
        Obj *a2 = *arg3;
        s32 s1 = first(a);
        VEnt *e = &a2->vt->e;
        e->fn(b, (char *)a2 + e->delta);
        MWidgetReader__structor_2(s1, o, b, s4);
        str_release((char **)b);
        if (arg0 != o) {
            s32 v = o[0];
            if (v != 0) func_003285A8(v);
            s32 old = *arg0;
            if (old != 0) func_003285F8(old);
            *arg0 = v;
        }
        func_00211408(a, 2);
    }
    func_002292A0(o, 2);
}
