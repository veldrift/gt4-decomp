/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct VE { s16 delta; s16 idx; void *fn; };
struct In { char pad[0x88]; s32 f88; u32 f8C; };
struct Obj {
    char pad0[0xC]; char *vt;
    char pad10[0x544 - 0x10]; char c544;
    char pad545[0x570 - 0x545]; s32 o570; s32 o574;
};
extern "C" void func_00391DC8(float);
extern "C" void func_003B76F0(void *, s32, s32, void *);
extern "C" s32 RaceOrganization__getLicenseRank(void *, s32);
extern "C" void func_003E1FB0(Obj *, void *);
extern "C" void GranTurismo4__GetTimeString(u32, void *, u32);
extern "C" void func_003E1EA0(Obj *self, In *arg) {
    s32 *s1 = (s32 *)((char *)arg + 0x88);
    if (self->o574 == 0) {
        func_00391DC8(1.0f);
        func_003B76F0(((char *)arg + 0xF4), 0x18, 0x18, 0);
        self->o570 = s1[0];
        self->o574 = 1;
        GranTurismo4__GetTimeString(s1[1], (char *)self + 0x6C, 0x20);
        if (s1[1] != 0x157529FF) {
            self->c544 = 0x2B;
            GranTurismo4__GetTimeString(s1[1] - RaceOrganization__getLicenseRank(arg, 3), (char *)self + 0x545, 0x1F);
        }
        VE *e = (VE *)(self->vt + 0x38);
        ((void (*)(void *, void *))e->fn)((char *)self + e->delta, arg);
        func_003B76F0(((char *)arg + 0xF4), 0x16, 0, 0);
        if (s1[0] != 0) func_003E1FB0(self, arg);
    }
}
