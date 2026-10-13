typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vt;
};

struct VEntry_2F8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, u8 *, u8 *, u8 *, u8 *);
};

extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00221AD0(void *arg0, int arg1);

extern "C" void func_00224728(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 *p_fp;
    s32 *p_s7;
    s32 *p_s6;
    s32 *p_s1;
    char *obj;
    VEntry_2F8 *e;
    u8 *x1;
    u8 *r1;
    u8 *r2;
    u8 *r3;
    u8 *r4;
    void *t1;
    s32 newVal;
    s32 oldVal;

    if (arg2 >= 0x4) {
        func_00221B28(buf0, arg1);
        func_00312370(buf1, arg3);
        p_fp = buf2;
        func_00312370(p_fp, (char *)arg3 + 0x4);
        p_s7 = buf3;
        func_00312370(p_s7, (char *)arg3 + 0x8);
        p_s6 = buf4;
        func_00312370(p_s6, (char *)arg3 + 0xC);
        x1 = (u8 *)buf1[0];
        obj = (char *)buf0[0];
        e = (VEntry_2F8 *)(((Obj *)obj)->vt + 0x2F8);
        obj = obj + e->delta;
        r1 = func_00314920(x1);
        r2 = func_00314920((u8 *)p_fp[0]);
        r3 = func_00314920((u8 *)p_s7[0]);
        r4 = func_00314920((u8 *)p_s6[0]);
        t1 = e->fn(obj, r1, r2, r3, r4);
        p_s1 = buf5;
        func_002FE278(p_s1, t1);
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
        func_00312318(p_s6, 0x2);
        func_00312318(p_s7, 0x2);
        func_00312318(p_fp, 0x2);
        func_00312318(buf1, 0x2);
        func_00221AD0(buf0, 0x2);
    }
}
