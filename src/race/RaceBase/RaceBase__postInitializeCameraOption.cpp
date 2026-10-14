typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct VEntry_C00 {
    s16 delta;
    s16 index;
    char *(*fn)(void *self, s32 a1);
};

struct Obj_C00 {
    char pad0[0x64];
    char *vt;
    char pad1[0xCC8 - 0x68];
    u32 fCC8;
    char pad2[0xCD0 - 0xCCC];
    u32 fCD0;
};

extern char *D_00622F4C;

extern "C" void CameraSys__CameraManager__initOptionInfo_mount(char *arg0, s32 arg1, s32 arg2);
extern "C" int RaceBase__getCameraMountModeFromOption(int a);

extern "C" void RaceBase__postInitializeCameraOption(Obj_C00 *self) {
    if (self->fCD0 == 0 && self->fCC8 < 2) {
        VEntry_C00 *e = (VEntry_C00 *)(self->vt + 0xD0);
        char *r = e->fn((char *)self + e->delta, 0);
        CameraSys__CameraManager__initOptionInfo_mount(r, 0, RaceBase__getCameraMountModeFromOption(*(s32 *)(D_00622F4C + 0x39DA4)));
    }
}
