typedef int s32;

struct Disp_0064B4B8 {
    char pad0[8];
    s32 (*f8)(void *, s32, void *, void *);
    s32 (*fC)(void *, s32, s32, void *, void *);
};

struct Obj_00536A78 {
    char pad0[0x164];
    void *f164;
};

extern void *D_0064B4B8;
extern s32 D_0064B47C;

extern "C" void func_005325C8(s32 arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" s32 func_00536B40();

extern "C" void func_00536A78(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 sp[4];
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    sp[0] = -1;
    if (((struct Disp_0064B4B8 *)D_0064B4B8)->f8(((struct Obj_00536A78 *)arg3)->f164, temp_s0, sp, D_0064B4B8) == 0) {
        if (((struct Disp_0064B4B8 *)D_0064B4B8)->fC(((struct Obj_00536A78 *)arg3)->f164, temp_s0, sp[0], (void *)(D_0064B47C + 0x60), (void *)(D_0064B47C + 0x68)) == 0) {
            func_005325C8(func_00536B40(), (char *)arg3, temp_s0, arg1, arg2);
        }
    }
}
