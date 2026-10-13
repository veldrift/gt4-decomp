typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" void func_00203118(void *arg0, int arg1);
extern "C" void func_00203148(void *arg0, f32 a, f32 b, f32 c, f32 d);
extern "C" void func_00203620(void *arg0, int arg1);
extern "C" void func_00203678(void *arg0, void *arg1);
extern "C" void func_00204558(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_002039E0(s32 *arg0, s32 arg1, char *arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s1;
    s32 *p_s3;
    s32 *p_s4;
    char *pa;
    char *pb;
    f32 t;
    f32 u;
    s32 newVal;
    s32 oldVal;
    if (arg1 >= 0x3) {
        func_00203678(buf0, arg2);
        p_s4 = buf1;
        func_00203678(p_s4, arg2 + 4);
        t = vcall_60((char *)(*(s32 *)(arg2 + 8)));
        p_s3 = buf2;
        pb = (char *)p_s4[0] + 0x10;
        u = 1.0f - t;
        pa = (char *)buf0[0] + 0x10;
        func_00203148(p_s3,
                      *(f32 *)(pa + 0x0) * t + *(f32 *)(pb + 0x0) * u,
                      *(f32 *)(pa + 0x4) * t + *(f32 *)(pb + 0x4) * u,
                      *(f32 *)(pa + 0x8) * t + *(f32 *)(pb + 0x8) * u,
                      *(f32 *)(pa + 0xC) * t + *(f32 *)(pb + 0xC) * u);
        p_s1 = buf3;
        func_00204558(p_s1, p_s3);
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
        func_00203620(p_s1, 0x2);
        func_00203118(p_s3, 0x2);
        func_00203620(p_s4, 0x2);
        func_00203620(buf0, 0x2);
    }
}
