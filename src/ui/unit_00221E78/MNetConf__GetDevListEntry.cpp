typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Obj {
    char pad0[4];
    char *vt;
};

struct VEntry {
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
extern "C" s32 func_002FE250(s32 arg0);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_002EEEB0(void *arg0, void *arg1, void *arg2);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_00312318(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_00221AD0(void *arg0, s32 arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00224198(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 b0[4];
    s32 b1[4];
    s32 b2[4];
    s32 b3[4];
    Str t40;
    Str t50;
    Str t60;
    Str t70;
    s32 *p_s7;
    s32 *p_s6;
    void *p_s4;
    s32 newVal;
    s32 oldVal;

    if (arg2 > 0) {
        func_00221B28(b0, arg1);
        p_s7 = b1;
        func_002FC8C8(p_s7, arg3);
        p_s6 = b2;
        func_002EFBF0(p_s6);
        p_s4 = b3;
        {
            void *self = (void *)p_s6[0];
            char *obj = (char *)b0[0];
            Str *h = &t50;
            VEntry *e = (VEntry *)(((Obj *)obj)->vt + 0x2D0);
            s32 k0 = p_s7[0];
            obj = obj + e->delta;
            s32 t2 = func_002FE250(k0);
            e->fn(h, obj, t2);
            func_00314B20(&t40, h);
            func_002EEEB0(p_s4, self, &t40);
            func_00309378(p_s4, 2);
            func_00312318(&t40, 2);
            str_release(h);
        }
        {
            void *self = (void *)p_s6[0];
            char *obj = (char *)b0[0];
            Str *h = &t70;
            VEntry *e = (VEntry *)(((Obj *)obj)->vt + 0x2D8);
            s32 k0 = p_s7[0];
            obj = obj + e->delta;
            s32 t2 = func_002FE250(k0);
            e->fn(h, obj, t2);
            func_00314B20(&t60, h);
            func_002EEEB0(p_s4, self, &t60);
            func_00309378(p_s4, 2);
            func_00312318(&t60, 2);
            str_release(h);
        }

        if (arg0 != p_s6) {
            newVal = *p_s6;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002ED5C0(p_s6, 2);
        func_002FC870(p_s7, 2);
        func_00221AD0(b0, 2);
    }
}
