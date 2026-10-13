typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;
struct S;

struct Obj {
    char pad0[4];
    char *vt;
};

struct VEntryA {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntryB {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *, s32);
};

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

extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" void func_002EFBF0(void *arg0);
extern "C" s32 func_002FE250(S *arg0);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void *func_002EEEB0(void *ret, void *self, void *x);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, s32 arg1);
extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_00221AD0(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00223C28(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    Str t40;
    Str t50;
    Str t60;
    Str t70;
    Str t80;
    Str t90;
    Str tA0;
    s32 *p_s7;
    s32 *p_s5;
    s32 *p_s4;
    s32 newVal;
    s32 oldVal;

    if (arg2 > 0) {
        func_00221B28(buf0, arg1);
        p_s7 = buf1;
        func_002FC8C8(p_s7, arg3);
        p_s5 = buf2;
        func_002EFBF0(p_s5);
        p_s4 = buf3;
        {
            void *self = (void *)p_s5[0];
            char *obj = (char *)buf0[0];
            VEntryA *e = (VEntryA *)(((Obj *)obj)->vt + 0x2A0);
            s32 k0 = p_s7[0];
            obj = obj + e->delta;
            s32 t2 = func_002FE250((S *)k0);
            void *t1 = e->fn(obj, t2);
            func_002FE278(&t40, t1);
            func_002EEEB0(p_s4, self, &t40);
            func_00309378(p_s4, 2);
            func_002FC870(&t40, 2);
        }
        {
            void *self = (void *)p_s5[0];
            char *obj = (char *)buf0[0];
            Str *h = &t60;
            VEntryB *e = (VEntryB *)(((Obj *)obj)->vt + 0x2A8);
            s32 k0 = p_s7[0];
            obj = obj + e->delta;
            s32 t2 = func_002FE250((S *)k0);
            e->fn(h, obj, t2);
            func_00314B20(&t50, h);
            func_002EEEB0(p_s4, self, &t50);
            func_00309378(p_s4, 2);
            func_00312318(&t50, 2);
            str_release(h);
        }
        {
            void *self = (void *)p_s5[0];
            char *obj = (char *)buf0[0];
            Str *h = &t80;
            VEntryB *e = (VEntryB *)(((Obj *)obj)->vt + 0x2B0);
            s32 k0 = p_s7[0];
            obj = obj + e->delta;
            s32 t2 = func_002FE250((S *)k0);
            e->fn(h, obj, t2);
            func_00314B20(&t70, h);
            func_002EEEB0(p_s4, self, &t70);
            func_00309378(p_s4, 2);
            func_00312318(&t70, 2);
            str_release(h);
        }
        {
            void *self = (void *)p_s5[0];
            char *obj = (char *)buf0[0];
            Str *h = &tA0;
            VEntryB *e = (VEntryB *)(((Obj *)obj)->vt + 0x2B8);
            s32 k0 = p_s7[0];
            obj = obj + e->delta;
            s32 t2 = func_002FE250((S *)k0);
            e->fn(h, obj, t2);
            func_00314B20(&t90, h);
            func_002EEEB0(p_s4, self, &t90);
            func_00309378(p_s4, 2);
            func_00312318(&t90, 2);
            str_release(h);
        }

        if (arg0 != p_s5) {
            newVal = *p_s5;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002ED5C0(p_s5, 2);
        func_002FC870(p_s7, 2);
        func_00221AD0(buf0, 2);
    }
}
