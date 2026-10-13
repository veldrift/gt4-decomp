typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry_328 { s16 delta; s16 index; void *(*fn)(void *, void *, void *); };
struct VObj_328 { char pad0[4]; VEntry_328 *vtbl; };

extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_00221AD0(void *arg0, int arg1);
extern "C" void func_00312318(void *arg0, int arg1);

extern "C" void MNetConf__GetProperties(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s4;
    s32 *p_s1;
    s32 *p_s5;
    char *obj;
    VEntry_328 *e;
    u8 *r0;
    void *t1;
    s32 newVal;
    s32 oldVal;

    func_00312370(buf0, arg3);
    p_s5 = buf1;
    func_00312370(p_s5, (char *)arg3 + 4);
    p_s4 = buf3;
    func_00221B28(p_s4, arg1);
    obj = (char *)*p_s4;
    e = (VEntry_328 *)((char *)((VObj_328 *)obj)->vtbl + 0x328);
    obj = obj + e->delta;
    r0 = func_00314920((u8 *)buf0[0]);
    {
        u8 *r1 = func_00314920((u8 *)p_s5[0]);
        t1 = e->fn(obj, r0, r1);
    }
    p_s1 = buf2;
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
    func_00221AD0(p_s4, 0x2);
    func_00312318(p_s5, 0x2);
    func_00312318(buf0, 0x2);
}
