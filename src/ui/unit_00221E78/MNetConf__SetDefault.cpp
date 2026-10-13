typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

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

struct VEntry_18 { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj_18 { char pad0[4]; VEntry_18 *vtbl; };
static inline void vcall_18_ret(void *ret, char *o) {
    VEntry_18 *e = (VEntry_18 *)((char *)((VObj_18 *)o)->vtbl + 0x18);
    e->fn(ret, o + e->delta);
}

struct VEntry_338 { s16 delta; s16 index; void *(*fn)(void *, void *, void *); };

extern "C" void func_00221B28(void *, void *);
extern "C" void func_00221AD0(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 * func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00224F88(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 bufA[4];
    Str s20;
    Str s30;
    s32 *pA;
    Str *ps20;
    char *o3;
    char *o1;
    char *vt;
    VEntry_338 *e;
    char *self1;
    char *o4;
    void *r;
    s32 newVal;
    s32 oldVal;

    pA = bufA;
    func_00221B28(pA, arg1);
    o3 = *(char **)arg3;
    ps20 = &s20;
    o1 = (char *)pA[0];
    vt = *(char **)(o1 + 4);
    e = (VEntry_338 *)(vt + 0x338);
    self1 = o1 + e->delta;
    vcall_18_ret((char *)ps20, o3);
    o4 = *(char **)((char *)arg3 + 4);
    vcall_18_ret((char *)&s30, o4);
    r = e->fn(self1, ps20, &s30);
    func_002FE278(buf0, r);
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
    func_002FC870(buf0, 0x2);
    str_release(&s30);
    str_release(ps20);
    func_00221AD0(pA, 0x2);
}
