/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VEnt { s16 off; s16 pad; void *(*fn)(void *); };
struct VEntV { s16 off; s16 pad; void (*fn)(void *); };

struct Item;
struct Lst { s32 count; s32 unk4; Item **items; };
struct Obj60 { char pad[0x20]; char *vt; };
struct Org { char pad[0x60]; Obj60 *unk60; };
struct Lst2 { char pad[8]; Item **unk8; };
struct Org2 { char pad[0x60]; Lst2 *unk60; };

struct Self {
    char pad0[0x64];
    char *unk64;
    char pad68[4];
    Org *unk6C;
    char pad70[0xCC8 - 0x70];
    u32 unkCC8;
};

extern s32 RaceSolitaire__disable_logger_;
extern "C" void AutomobileControlRecord__Manager__reset(void *);
extern "C" void RaceBasic__initialize(void *, void *);
extern "C" void RaceEntryCar__toGhost(void *, void *, s32);

extern "C" void RaceSolitaire__initialize(Self *self, void *arg1) {
    VEntV *ve = (VEntV *)(self->unk64 + 0x4D0);
    ve->fn((char *)self + ve->off);
    RaceBasic__initialize(self, arg1);
    if (self->unkCC8 < 2) {
        AutomobileControlRecord__Manager__reset((char *)self + 0xEFE0);
        AutomobileControlRecord__Manager__reset((char *)self + 0xEF70);
    }
    *(s32 *)((char *)self + 0xF0F4) = 0;
    if (*(s32 *)((char *)self + 0xF100) == 0 && RaceSolitaire__disable_logger_ == 0) {
        Org *org = self->unk6C;
        Obj60 *o = org->unk60;
        VEnt *v1 = (VEnt *)(o->vt + 0x10);
        void *r = v1->fn((char *)o + v1->off);
        *(void **)((char *)self + 0xF100) = r;
        RaceEntryCar__toGhost(r, ((Org2 *)org)->unk60->unk8[0], 0);
        Obj60 *o2 = org->unk60;
        VEntV *v2 = (VEntV *)(o2->vt + 0x18);
        v2->fn((char *)o2 + v2->off);
    }
}
