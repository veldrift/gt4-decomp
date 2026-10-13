typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct VEntry_337008 {
    s16 delta;
    s16 index;
    char *(*fn)(void *self, s32 a1);
};

struct Obj_337008 {
    char pad0[0x64];
    char *vt;
    char pad1[0xCC8 - 0x68];
    u32 fCC8;
    char pad2[0xE454 - 0xCCC];
    s32 fE454;
};

extern char *D_00622F4C;

extern "C" s32 CameraSys__CameraManager__getOptionInfo_mount(char *arg0, s32 arg1);
extern "C" s32 RaceBase__getCameraMountModeToOption(s32 a);

extern "C" void RaceLanBattle__virtual_50(Obj_337008 *self) {
    if (self->fCC8 < 2 && self->fE454 != 0) {
        VEntry_337008 *e = (VEntry_337008 *)(self->vt + 0xD0);
        char *r = e->fn((char *)self + e->delta, 0);
        *(s32 *)(D_00622F4C + 0x39DA4) = RaceBase__getCameraMountModeToOption(CameraSys__CameraManager__getOptionInfo_mount(r, 0));
    }
}
