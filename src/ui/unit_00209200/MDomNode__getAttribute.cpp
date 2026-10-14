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

struct Obj {
    char pad[0x30];
    char *str;
};

struct S00659988 {
    const char *name;
};

extern "C" void func_00312370(void *, s32);
extern "C" void func_00208F70(void *, s32);
extern "C" u8 *func_00314920(u8 *);
extern "C" void func_00209C30(void *, void *, void *);
extern "C" void func_00208F18(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MDomNode__getAttribute(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    Str s3;
    s32 *p_s1;
    s32 *p_s4;
    Str *p_s3;
    void *v_s0;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_00312370(buf0, arg3);
        p_s1 = buf2;
        p_s4 = buf1;
        func_00208F70(p_s1, arg1);
        v_s0 = (void *)p_s1[0];
        func_00209C30(p_s4, v_s0, func_00314920((u8 *)buf0[0]));
        func_00208F18(p_s1, 2);
        if (p_s4[0] != 0) {
            Obj *o = (Obj *)p_s4[0];
            char *d = o->str;
            Rep *r = (Rep *)(d - 0x10);
            p_s3 = &s3;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                r->ref++;
            }
            p_s3->p = d;
            func_00314B20(p_s1, p_s3);
            if (arg0 != p_s1) {
                newVal = p_s1[0];
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *arg0;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *arg0 = newVal;
            }
            func_00312318(p_s1, 2);
            str_release(p_s3);
        }
        func_00208F18(p_s4, 2);
        func_00312318(buf0, 2);
    }
}
