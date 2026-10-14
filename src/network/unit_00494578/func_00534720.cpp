typedef int s32;
struct Res { s32 unk0; s32 unk4; };
extern s32 D_0064B4F0;
extern "C" void *func_00535A18(unsigned int);
extern "C" s32 func_00535F28(void *, s32 *);
extern "C" void func_005347F8(void *, s32 *, Res *);
extern "C" s32 func_00534720(s32 *arg0, Res *arg1) {
    s32 sp0 = 0;
    if (arg1 == 0) return 0x17;
    arg1->unk4 = 0x1E;
    arg1->unk0 = 1;
    if (arg0 == 0) {
        arg1->unk4 = 0x17;
        return 0x17;
    }
    if (*arg0 == 0) {
        arg1->unk4 = 0x26;
        return 0x26;
    }
    if (D_0064B4F0 == 0) {
        arg1->unk4 = 0x1A;
        return 0x1A;
    }
    arg1->unk4 = func_00535F28(func_00535A18(0), &sp0);
    if (arg1->unk4 == 0 && sp0 != 0) {
        func_005347F8(func_00535A18(0), arg0, arg1);
    }
    return arg1->unk4;
}
