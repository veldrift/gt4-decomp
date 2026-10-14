/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; char *(*fn)(void *, int); };
struct Obj { char pad0[0x64]; VEntry *vt; char pad1[0xCC8-0x68]; unsigned int mode; };
struct Option { char pad[0x10F4]; int a; int b; };
extern char *D_00622F4C;
extern "C" int CameraSys__CameraManager__getOptionInfo_mount(char *, int);
extern "C" int RaceBase__getCameraMountModeToOption(int);
static inline void setA(Option *o, int v) { o->a = v; }
static inline void setB(Option *o, int v) { o->b = v; }
extern "C" void RaceSplitBattleBase__cleanupCameraOption(Obj *self) {
    VEntry *e = &self->vt[26];
    char *camera = e->fn((char *)self + e->delta, 0);
    if (self->mode < 2) {
        int a = CameraSys__CameraManager__getOptionInfo_mount(camera, 0);
        char *base = D_00622F4C;
        setA((Option *)(base + 0x38CB0), RaceBase__getCameraMountModeToOption(a));
        a = CameraSys__CameraManager__getOptionInfo_mount(camera, 1);
        char * base_2 = D_00622F4C;
        setB((Option *)(base_2 + 0x38CB0), RaceBase__getCameraMountModeToOption(a));
    }
}
