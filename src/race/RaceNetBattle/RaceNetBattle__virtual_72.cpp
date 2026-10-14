/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0x64]; char *vtbl; char pad1[0x22c50 - 0x68]; int status; };
struct VEntry { short delta, index; void (*fn)(void *, int, float, float); };
extern "C" char D_00645570[];
extern "C" char D_0069F208[];
extern "C" int func_004FB1E8(char *);
extern "C" int func_004F23D8(char *);
extern "C" void func_0038BC98(Obj *, char *, float, int);
extern "C" int RacePS2Base__updateCommon(Obj *);
extern "C" int RaceNetBattle__virtual_72(Obj *self) {
    self->status = func_004FB1E8(D_00645570);
    if (func_004F23D8(D_00645570) == 1) {
        float time = 5.0f;
        func_0038BC98(self, D_0069F208, time, 0);
        VEntry *e = (VEntry *)(self->vtbl + 0x2b8);
        e->fn((char *)self + e->delta, 7, time, 0.5f);
    }
    return RacePS2Base__updateCommon(self);
}
