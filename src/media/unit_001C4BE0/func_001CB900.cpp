typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef long s64;
typedef float f32;

struct func_001CB900_arg0 {
    char pad0[0x38];
    s32 unk38;
    s32 unk3C;
};

extern "C" void func_001D4B78(void *, s32, void *);
extern "C" void func_005792E8(void *, s32);
extern "C" u32 func_00579330(void *);
extern "C" void func_00579420(void *, s32);
extern "C" u32 func_005794C0(void *);

extern "C" void func_001CB900(void *arg0) {
    char buf0[0x9D0];
    s32 buf1[4];
    u32 i = 0;
    u8 *base = (u8 *)arg0;
    s32 s2 = ((struct func_001CB900_arg0 *)arg0)->unk38;
    u32 r;

    func_00579420(buf0, s2 + ((struct func_001CB900_arg0 *)arg0)->unk3C);
    do {
        base[i] = (u8)(base[i] ^ func_005794C0(buf0));
        i++;
    } while (i < 0x3C);
    func_005792E8(buf1, s2);
    r = func_00579330(buf1);
    ((struct func_001CB900_arg0 *)arg0)->unk3C = (s32)(((struct func_001CB900_arg0 *)arg0)->unk3C ^ r);
    func_00579420(buf0, func_00579330(buf1));
    func_001D4B78(arg0, 0x40, buf0);
}
