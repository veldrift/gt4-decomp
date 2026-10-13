typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vt;
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

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, const char *, const char *, s32);
};

extern char D_00698F10[];

extern "C" void func_002403C8(void *arg0, int arg1);
extern "C" void func_00240420(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_00698F10;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_00240E38(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s6;
    s32 *p_s5;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;

    if (arg2 >= 0x2) {
        func_00240420(buf0, arg1);
        p_s6 = buf1;
        func_00312370(p_s6, arg3);
        p_s5 = buf2;
        func_00312370(p_s5, (char *)arg3 + 0x4);
        {
            char *obj;
            VEntry *e;
            char *self;
            Str *k;
            Str *r;
            s32 len;
            s32 t1;

            k = (Str *)func_00314920((u8 *)p_s5[0]);
            len = ((Rep *)k->p)[-1].len;
            obj = (char *)buf0[0];
            e = (VEntry *)(((Obj *)obj)->vt + 0x1C8);
            self = obj + e->delta;
            r = (Str *)func_00314920((u8 *)p_s6[0]);
            t1 = e->fn(self, c_str(r), c_str(k), len);
            if (t1 >= 0) {
                p_s1 = buf3;
                func_002FE278(p_s1, (void *)1);
                if (arg0 != p_s1) {
                    newVal = *p_s1;
                    if (newVal != 0) {
                        func_003285A8((RefCounter *)newVal);
                    }
                    oldVal = *arg0;
                    if (oldVal != 0) {
                        func_003285F8((RefCounter *)oldVal);
                    }
                    *arg0 = newVal;
                }
                func_002FC870(p_s1, 0x2);
            } else {
                p_s1 = buf3;
                func_002FE278(p_s1, (void *)0);
                if (arg0 != p_s1) {
                    newVal = *p_s1;
                    if (newVal != 0) {
                        func_003285A8((RefCounter *)newVal);
                    }
                    oldVal = *arg0;
                    if (oldVal != 0) {
                        func_003285F8((RefCounter *)oldVal);
                    }
                    *arg0 = newVal;
                }
                func_002FC870(p_s1, 0x2);
            }
        }
        func_00312318(p_s5, 0x2);
        func_00312318(p_s6, 0x2);
        func_002403C8(buf0, 0x2);
    }
}
