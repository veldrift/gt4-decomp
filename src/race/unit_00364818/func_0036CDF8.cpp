/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Self {
    char pad0[0xFD8];
    f32 unkFD8;
    char pad1[0x1074 - 0xFDC];
    u8 unk1074;
    u8 unk1075;
};

struct Obj {
    char pad0[0x6244D8];
    s32 unk6244D8;
};

extern int PDISTD__UNIT_MANAGER;

extern "C" void func_0036CDF8(Self *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = PDISTD__UNIT_MANAGER;
    s32 n = (s32)((arg0->unkFD8 * 1.1f) / 22.22222f) + 1;
    s32 k = n;
    if (k < 2) {
        k = 2;
    } else if (k >= 5) {
        k = 4;
    }
    if (*arg1 == 0) {
        *arg2 = k * 0x50;
    } else {
        *arg2 = k * 0x32;
    }
    *arg3 = arg0->unk1074 * 100;
    *arg4 = arg0->unk1075 * 1000;
}
