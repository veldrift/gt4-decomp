typedef int s32;
typedef unsigned int u32;

struct VE { short d; short i; s32 (*fn)(void *); };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad68[4];
    void *f6C;
};
struct Obj2 { char pad[0xCC8]; s32 fCC8; char padCCC[0xF1F8 - 0xCCC]; s32 fF1F8; };

extern "C" void func_0038B7C0(void *, void *);
extern "C" void func_0038B8D8(void *, void *);
extern "C" void RaceDisplay__setOrganization(void *, void *);
extern "C" void RaceDisplay__virtual_06(void *, s32);
extern "C" void RaceDisplay__virtual_07(void *, s32);
extern "C" void func_003DF970(void *, void *);
extern "C" void RaceSolitaire__initialize(void *, s32);

extern "C" void RaceMachineTest__initialize(Obj *o, s32 arg1) {
    char *s2;
    func_0038B8D8(o, 0);
    func_0038B7C0(o, 0);
    char *s1 = (char *)o + 0xF6A8;
    RaceSolitaire__initialize(o, arg1);
    if ((u32)(((Obj2 *)o)->fCC8 - 2) < 2) {
        func_0038B7C0(o, 0);
        func_0038B8D8(o, 0);
        func_0038B8D8(o, 0);
    } else {
        s2 = (char *)o + 0xF1A8;
        func_0038B7C0(o, (char *)o + 0xF170);
        func_0038B8D8(o, s2);
        func_003DF970(s2, (char *)o + 0xF140);
    }
    RaceDisplay__setOrganization(s1, o->f6C);
    RaceDisplay__virtual_06(s1, 5);
    RaceDisplay__virtual_07(s1, arg1);
    VE *ve = (VE *)(o->vt + 0x2F8);
    s32 r = ve->fn((char *)o + ve->d);
    if (r == 0x12) ((Obj2 *)o)->fF1F8 = 4; else ((Obj2 *)o)->fF1F8 = 5;
}
