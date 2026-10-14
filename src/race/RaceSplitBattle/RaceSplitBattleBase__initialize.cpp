/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VObj;
struct VEntry { s16 delta; s16 pad; void (*fn)(void *); };
struct VEntryR { s16 delta; s16 pad; VObj *(*fn)(void *); };
struct VObj { VEntry *vtbl; };
struct VObj2 { char *vtbl; };

struct Self {
    char pad0[0x64];
    char *tbl;
    char pad68[0xCC8 - 0x68];
    u32 mode;
};

extern "C" void RaceBasic__initialize(void *, void *);
extern "C" void RaceInput__setRunMode(void *, void *);
extern "C" void func_0038B7C0(void *, void *);
extern "C" void func_0038B8D8(void *, void *);
extern "C" void func_0033CC88(void *);
extern "C" void func_00398B48(void *);

extern "C" void RaceSplitBattleBase__initialize(Self *self, void *arg1) {
    char *p = (char *)self + 0x1E5C8;
    int i = 1;
    RaceBasic__initialize(self, arg1);
    do {
        char *q = p;
        p += 0x1E0;
        i--;
        RaceInput__setRunMode(q, arg1);
    } while (i >= 0);
    if (self->mode - 2 < 2) {
        func_0038B7C0(self, (char *)self + 0x1EEB8);
        func_0038B8D8(self, 0);
    } else {
        func_0038B7C0(self, (char *)self + 0x1EEB8);
        func_0038B8D8(self, (char *)self + 0x1E9B8);
    }
    func_0033CC88(self);
    VEntryR *e = (VEntryR *)(self->tbl + 0x4C8);
    VObj *o = e->fn((char *)self + e->delta);
    VEntry *e2 = (VEntry *)((char *)o->vtbl + 0x48);
    e2->fn((char *)o + e2->delta);
    func_00398B48((char *)self + 0xE170);
}
