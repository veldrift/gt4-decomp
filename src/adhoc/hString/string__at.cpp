typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
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

struct VEntry_58 { s16 delta; s16 index; u32 (*fn)(void *); };

extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, u8 arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_0030BB18(void *a0);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_005CB5A0(void *str, u32 size, int save);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00313E20(s32 *arg0, char **arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    u32 idx;

    if (arg2 == 0x1) {
        char *o3 = *arg3;
        char *vt = *(char **)(o3 + 4);
        VEntry_58 *e = (VEntry_58 *)(vt + 0x58);
        idx = e->fn(o3 + e->delta);
        vcall_18_ret(buf0, *arg1);
        Rep *r = (Rep *)((char *)buf0[0] - 0x10);
        if (idx < (u32)r->len) {
            if ((u32)r->ref >= 2) {
                func_005CB5A0(buf0, r->len, 1);
            }
            *(s32 *)((char *)buf0[0] - 4) = arg2;
            p_s2 = buf1;
            func_002FE278(p_s2, *((u8 *)buf0[0] + idx));
            if (arg0 != p_s2) {
                newVal = *p_s2;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *arg0;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *arg0 = newVal;
            }
            func_002FC870(p_s2, 0x2);
            str_release((Str *)buf0);
            return;
        }
        str_release((Str *)buf0);
    }
    func_0030BB18(buf0);
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
    func_00309378(buf0, 0x2);
}
