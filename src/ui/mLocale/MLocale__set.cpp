typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef long s64;
typedef float f32;

extern char D_0069C0A8[];
extern u32 D_00624978[];

extern "C" void func_00312370(void *, void *);
extern "C" u8 *func_00314920(u8 *);
extern "C" s32 func_0048EEB8(u32 *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00312318(void *, s32);

extern "C" void func_002B61F8(s32 *arg0, s32 arg1, void *arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        func_00312370(buf0, arg2);
        void **pp = (void **)func_00314920((u8 *)buf0[0]);
        char *v1 = (char *)*pp;
        s32 len = *(s32 *)(v1 - 0x10);
        char *s;
        if (len == 0) {
            s = D_0069C0A8;
        } else {
            v1[len] = 0;
            s = (char *)*pp;
        }
        t1 = func_0048EEB8(D_00624978, (s32)s);
        p_s1 = buf1;
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
        func_00312318(buf0, 0x2);
    }
}
