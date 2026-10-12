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

extern "C" void func_0038FA88(void *);

extern "C" void RaceEntryCar__copyVehicleModel(s32 *arg0) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x11f0;
    func_0038FA88(v_s0);
    *(s32 *)((char *)arg0 + 0x2880) = (s32)v_s0;
    *(s32 *)(char *)v_s0 = (s32)(char *)arg0 + 0x2890;
    *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x2880)) + 0x4) = *(s32 *)((char *)arg0 + 0x18);
}
