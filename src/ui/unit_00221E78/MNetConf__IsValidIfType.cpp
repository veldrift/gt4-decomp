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

struct VEntry_2E8 { s16 delta; s16 index; void *(*fn)(void *, void *); };
struct VObj_2E8 { char pad0[4]; char *vtbl; };

extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_00221AD0(void *arg0, s32 arg1);
extern "C" void func_00312318(void *arg0, s32 arg1);

extern "C" void func_002244C0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    void *t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_00312370(buf0, arg3);
        p_s3 = buf2;
        func_00221B28(p_s3, arg1);
        {
            char *obj = (char *)*p_s3;
            VEntry_2E8 *e = (VEntry_2E8 *)(((VObj_2E8 *)obj)->vtbl + 0x2E8);
            obj = obj + e->delta;
            void *r = func_00314920((u8 *)buf0[0]);
            t1 = e->fn(obj, r);
        }
        s32 *p_s1 = buf1;
        func_002FE278(p_s1, t1);
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
        func_002FC870(p_s1, 0x2);
        func_00221AD0(p_s3, 0x2);
        func_00312318(buf0, 0x2);
    }
}
