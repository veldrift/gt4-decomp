typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef long s64;
typedef float f32;

struct func_001CB9B8_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

extern "C" void func_005792E8(s32 *arg0, s32 arg1);
extern "C" u32 func_00579330(u32 *arg0);
extern "C" void func_00579420(void *arg0, s32 arg1);
extern "C" void func_001D4BA0(void *arg0, s32 arg1, void *arg2);
extern "C" u32 func_005794C0(void *arg0);

extern "C" void func_001CB9B8(void *arg0, s32 arg1) {
    s32 mt0[4];
    s32 mt1[4];
    char pad[0x9C0];
    u32 i = 0;
    u8 *base = (u8 *)arg0;
    u32 r;
    s32 t;

    func_005792E8(mt0, arg1);
    r = func_00579330((u32 *)mt0);
    func_00579420(mt1, (s32)func_00579330((u32 *)mt0));
    func_001D4BA0(arg0, 0x40, mt1);
    t = ((struct func_001CB9B8_arg0 *)arg0)->unk3C ^ (s32)r;
    ((struct func_001CB9B8_arg0 *)arg0)->unk3C = t;
    func_00579420(mt1, arg1 + t);
    do {
        base[i] = (u8)(base[i] ^ func_005794C0(mt1));
        i++;
    } while (i < 0x3C);
}
