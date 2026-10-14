/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VEnt { s16 off; s16 pad; void *(*fn)(void *); };
struct VTab { char pad[0x90]; VEnt e90; };

struct Item { char pad[0x3440]; s32 unk3440; };
struct Lst { s32 count; s32 unk4; Item **items; };
struct Org { char pad[0x60]; Lst *unk60; };

struct Info { char pad[0x84]; s32 unk84; s32 unk88; s32 unk8C; s32 unk90; };
struct Inp { char pad[0x14C]; s32 unk14C; };

struct Sub { char pad[0x10140]; char *unk10140; };

struct Self {
    char pad0[0x64];
    char *unk64;
    char pad68[4];
    Org *unk6C;
    Sub *unk70;
    char pad74[0xCC8 - 0x74];
    u32 unkCC8;
};

extern "C" void RaceInput__setRunMode(void *, u32);
extern "C" s32 RaceOrganization__getLoggerCheckPointCount(void *);
extern "C" Inp *RaceSolitaire__getInput(void *) throw();
extern "C" Inp *RaceSolitaire__getInputGhost(void *) throw();
extern "C" void RaceBase__initializeDynamicsConductor(void *);

extern "C" void RaceSolitaire__initializeDynamicsConductor(Self *self) {
    RaceInput__setRunMode((char *)self + 0xE48C, self->unkCC8);
    RaceInput__setRunMode((char *)self + 0xE84C, self->unkCC8);
    Org *org = self->unk6C;
    VEnt *ve = (VEnt *)(self->unk64 + 0x90);
    Info *info = (Info *)ve->fn((char *)self + ve->off);
    info->unk90 = RaceOrganization__getLoggerCheckPointCount(org);
    Item *first = org->unk60->items[0];
    u32 m = self->unkCC8;
    if (m < 2) {
        first->unk3440 = m;
    }
    u32 mode = 2;
    RaceSolitaire__getInput(self)->unk14C = info->unk84;
    if (org->unk60->count >= 2) {
        mode = (org->unk60->items[1]->unk3440 ^ 1) == 0 ? 3 : 2;
    }
    Inp *inp = RaceSolitaire__getInputGhost(self);
    RaceInput__setRunMode(inp, mode);
    inp->unk14C = info->unk8C;
    RaceBase__initializeDynamicsConductor(self);
    Sub *sub = self->unk70;
    VEnt *v1 = (VEnt *)(sub->unk10140 + 0x40);
    if (v1->fn((char *)sub + v1->off)) {
        VEnt *v2 = (VEnt *)(sub->unk10140 + 0x128);
        info->unk90 = (s32)v2->fn((char *)sub + v2->off);
    }
}
