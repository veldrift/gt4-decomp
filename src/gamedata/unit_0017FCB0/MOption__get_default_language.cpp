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
extern char D_006915D0[];
extern Rep D_00659FA8;
extern s32 D_00659FB4;
extern "C" void *func_0017FB28(void *, void *) throw();
extern "C" void func_004398C0(s32, const char *);
extern "C" void func_0017FAD0(void *, s32) throw();
extern "C" s32 func_004398B0(s32);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(s32) throw();
extern "C" void func_005C2630(void *, s32, s32, s32, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MOption__get_default_language(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    Str s1;
    s32 buf2[4];
    Str s3;
    s32 v_s0;
    const char *c;
    Str *p_s3;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_0017FB28(buf0, arg1);
        Str *t = &s1;
        s32 owner = buf0[0];
        vcall_18_ret(t, *arg3);
        c = 0;
        {
            if (*(s32 *)((char *)t->p - 0x10) == 0) {
                c = D_006915D0;
            } else {
                *(char *)((char *)t->p + *(s32 *)((char *)t->p - 0x10)) = 0;
                c = t->p;
            }
        }
        func_004398C0(*(s32 *)((char *)owner + 0x10) + 0x1650, c);
        str_release(t);
        func_0017FAD0(buf0, 0x2);
    } else {
        func_0017FB28(buf0, arg1);
        p_s3 = &s3;
        v_s0 = func_004398B0(*(s32 *)((char *)buf0[0] + 0x10) + 0x1650);
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            p_s3->p = d;
        }
        func_005C2630(p_s3, 0, -0x1, v_s0, func_0057F260(v_s0));
        p_s1 = buf2;
        func_00314B20(p_s1, p_s3);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(p_s1, 0x2);
        str_release(p_s3);
        func_0017FAD0(buf0, 0x2);
    }
}
