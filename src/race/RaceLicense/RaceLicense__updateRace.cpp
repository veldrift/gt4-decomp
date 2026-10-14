/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Org { char pad[0xDC]; s32 unkDC; };

struct Obj;
struct VEntV { s16 off; s16 pad; void (*fn)(void *); };
struct VEntO { s16 off; s16 pad; Obj *(*fn)(void *, s32); };
struct VEntI { s16 off; s16 pad; s32 (*fn)(void *); };
struct VEntB { s16 off; s16 pad; void (*fn)(void *, void *, s32, s32); };
struct Obj { char *vt; };

struct Self {
    char pad0[0x64];
    char *unk64;
    char pad68[4];
    Org *unk6C;
    s32 unk70;
    char pad74[0xD44 - 0x74];
    s32 unkD44;
    char padD48[0x24EE0 - 0xD48];
    s32 unk24EE0;
    s32 unk24EE4;
};

extern "C" void RacePS2Base__updateRace(void *);
extern "C" void RaceDisplay__virtual_16(void *, s32);
extern "C" void func_003BC6E0(void *, f32);
extern "C" void RaceLicenseDisplay__setDisplayTypeInReplay(void *, s32);

extern "C" void RaceLicense__updateRace(Self *self) {
    char *c = (char *)self + 0x10368;
    if (self->unk6C->unkDC != 0) {
        RaceDisplay__virtual_16(c, 0);
    }
    if (self->unk24EE0 != 0) {
        RaceDisplay__virtual_16(c, self->unk24EE4 != 0);
        RaceLicenseDisplay__setDisplayTypeInReplay(c, 2);
        if (self->unk24EE4 == 0) {
            VEntO *v0 = (VEntO *)(self->unk64 + 0xD0);
            Obj *o = v0->fn((char *)self + v0->off, 0);
            VEntI *v1 = (VEntI *)(o->vt + 0x158);
            if (v1->fn((char *)o + v1->off) == 0) {
                VEntB *v2 = (VEntB *)(o->vt + 0xB0);
                v2->fn((char *)o + v2->off, self->unk6C, self->unk70, self->unkD44 == 0);
                return;
            }
            VEntV *v3 = (VEntV *)(self->unk64 + 0x178);
            v3->fn((char *)self + v3->off);
            VEntV *v4 = (VEntV *)(self->unk64 + 0x180);
            v4->fn((char *)self + v4->off);
            self->unk24EE4 = 1;
        }
    }
    RacePS2Base__updateRace(self);
    func_003BC6E0(self, 0x1.111110p-6f);
}
