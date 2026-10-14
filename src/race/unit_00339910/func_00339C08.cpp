typedef int s32;
struct Ent { short delta; short pad; void *fn; };
struct Obj { char p0[8]; char *vt; char p1[0x1670 - 12]; s32 f1670; s32 f1674; };
struct Top { char p0[0x2880]; Obj *mid; };
extern char RaceCarModel__tf[];
extern char VehicleModel__tf[];
extern "C" void func_00339AD0(s32 a0, void *a1, void *a2, s32 a3);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(s32 a0, void *a1, s32 a2, void *a3, void *a4, void *a5);
typedef void (*F1)(void *);
typedef void (*F2)(void *, s32, s32, float);
extern "C" void func_00339C08(s32 arg0, Top *arg1, float fparg0) {
    float keep = fparg0;
    Obj *s0 = 0;
    Obj *v1 = arg1->mid;
    if (v1 != 0) {
        Ent *e = (Ent *)v1->vt;
        s0 = (Obj *)GT4MC__FileGT4GameData__loadInstance((s32)e->fn, RaceCarModel__tf, 0, (char *)v1 + e->delta, VehicleModel__tf, v1);
    }
    {
        Ent *e = (Ent *)(s0->vt + 0xE8);
        ((F1)e->fn)((char *)s0 + e->delta);
    }
    {
        Ent *e = (Ent *)(s0->vt + 0xF0);
        ((F2)e->fn)((char *)s0 + e->delta, 0, 0, keep);
    }
    if (s0 != 0) {
        if (s0->f1670 != 0) {
            func_00339AD0(arg0, (char *)s0 + 0x5F0, (char *)s0 + 0xDC0, 0);
        }
        if (s0->f1674 != 0) {
            func_00339AD0(arg0, (char *)s0 + 0xE30, (char *)s0 + 0x1600, 1);
        }
    }
}
