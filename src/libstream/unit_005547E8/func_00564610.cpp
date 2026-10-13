typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

extern char D_006C8D98[];

extern "C" void *func_005A48D8(void *, s32, s32);
extern "C" s32 func_005ADCA0(void *);
extern "C" s32 func_00563408(s32);

extern "C" void *func_00564610(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 buf[4];
    s32 spare[4];
    s32 zero;
    s32 n;
    s32 p;

    zero = 0;
    n = 0x2C;
    func_005A48D8(arg0, zero, n);
    arg0->unk20 = func_005ADCA0(D_006C8D98);
    arg0->unk4 = arg1 * arg2;
    p = func_00563408(6);
    arg0->unk0 = p;
    func_005A48D8((void *)p, zero, arg0->unk4);
    arg0->unk8 = arg1;
    arg0->unk24 = arg3;
    arg0->unk28 = arg4;
    arg0->unkC = arg2;
    arg0->unk14 = 0;
    arg0->unk10 = 0;
    arg0->unk18 = 0;
    buf[2] = arg2;
    buf[1] = arg2;
    arg0->unk1C = func_005ADCA0(buf);
    return arg0;
}
