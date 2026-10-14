/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

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
extern "C" void func_0030D390(void *, void *, void *) throw();
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

extern "C" void adhoc__GetAbsolute(s32 *arg0, s32 arg1, void *arg2) {
    Str s0;
    Str s1;
    s32 buf2[4];
    Str s3;
    Str *p_s4;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if (arg1 == 2) {
        vcall_18_ret((char *)&s0, (char *)(*(s32 *)(char *)arg2));
        p_s4 = &s1;
        vcall_18_ret((char *)p_s4, (char *)(*(s32 *)((char *)arg2 + 4)));
        func_0030D390(&s3, &s0, p_s4);
        p_s1 = buf2;
        func_00314B20(p_s1, &s3);
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
        str_release(&s3);
        str_release(p_s4);
        str_release(&s0);
    }
}
