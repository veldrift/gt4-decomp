/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct Org { char pad[0xF0]; s32 unkF0; };
struct VEntP { s16 off; s16 pad; s32 (*fn)(void *, s32 *); };

struct Self {
    char pad0[0x64];
    char *unk64;
    char pad68[4];
    Org *unk6C;
    char pad70[0xCC8 - 0x70];
    u32 unkCC8;
    char padCCC[0x24EE0 - 0xCCC];
    s32 unk24EE0;
};

extern "C" void RaceSolitaire__initialize(void *, void *);
extern "C" void func_003BC5D0(void *);
extern "C" void func_003BCAE0(void *);
extern "C" void func_0033CE70(void *, s32, s32);
extern "C" void func_0038B7C0(void *, void *);
extern "C" void func_0038B8D8(void *, void *);
extern "C" void RaceDisplay__setOrganization(void *, void *);
extern "C" void RaceDisplay__virtual_06(void *, s32);
extern "C" void RaceDisplay__virtual_07(void *, s32);
extern "C" void RaceDisplay__virtual_16(void *, s32);
extern "C" void func_003E0940(void *, s32, s32, s32);
extern "C" void func_003E09D8(void *, void *);

extern "C" void RaceLicense__initialize(Self *self, void *arg1) {
    char *c = (char *)self + 0x10368;
    s32 buf[4];
    RaceSolitaire__initialize(self, arg1);
    func_003BC5D0(self);
    func_003BCAE0(self);
    func_0033CE70(self, self->unk6C->unkF0, 1);
    if (self->unkCC8 - 2 < 2) {
        func_0038B7C0(self, (char *)self + 0xF140);
        func_0038B8D8(self, 0);
    } else {
        func_0038B7C0(self, (char *)self + 0xF140);
        func_0038B8D8(self, (char *)self + 0x24838);
    }
    RaceDisplay__setOrganization(c, self->unk6C);
    RaceDisplay__virtual_06(c, 3);
    RaceDisplay__virtual_07(c, (s32)arg1);
    RaceDisplay__virtual_16(c, self->unk24EE0);
    char *d = (char *)self + 0x24838;
    VEntP *v = (VEntP *)(self->unk64 + 0x300);
    func_003E0940(d, v->fn((char *)self + v->off, buf), buf[0], 0);
    func_003E09D8(d, self);
}
