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

struct S00659988 {
    const char *name;
};

extern "C" void func_0021B790(void *);
extern "C" void func_002106E0(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00210710(void *, s32);
extern "C" void func_00265F48(void *, s32);

extern "C" void func_0013A3D8(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s1;
    s32 newVal;
    s32 oldVal;
    v_s1 = (s32)((char *)arg0 + 0xcc);
    func_0021B790((char *)arg0 + 0xa0);
    buf1[0] = 0;
    func_002106E0(buf0, buf1);
    if ((char *)v_s1 != (char *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *(s32 *)(char *)v_s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *(s32 *)(char *)v_s1 = newVal;
    }
    func_00210710(buf0, 0x2);
    func_00265F48(arg0, 0);
}
