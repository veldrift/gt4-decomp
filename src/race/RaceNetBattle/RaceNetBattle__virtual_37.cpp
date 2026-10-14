/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x6C];
    int f6C;
};
struct Sing { char pad[0xCC4]; int fCC4; };
extern "C" Sing D_00645570;
extern "C" void RaceBasic__initialize(void *);
extern "C" void AutomobileControlRecord__Manager__reset(void *);
extern "C" void RaceInput__setRunMode(void *, int);
extern "C" void func_0043A138(void *);
extern "C" void func_0038B7C0(void *, void *);
extern "C" void func_0038B8D8(void *, void *);
extern "C" void func_003DF970(void *, void *);
extern "C" int func_004F9E60(void *, int);
extern "C" int func_004F9EC0(void *, int);
extern "C" void RaceDisplay__setOrganization(void *, int);
extern "C" void RaceDisplay__virtual_06(void *, int);
extern "C" void RaceDisplay__virtual_07(void *, int);

extern "C" void RaceNetBattle__virtual_37(Obj *o, int mode) {
    char *c = (char *)o;
    char *in = c + 0xE480;
    char *e = c + 0x1E7D8;
    char *d = c + 0x1ED1C;
    RaceBasic__initialize(o);
    AutomobileControlRecord__Manager__reset(c + 0xE554);
    RaceInput__setRunMode(in, mode);
    func_0043A138(c + 0xE5F0);
    func_0038B7C0(o, c + 0x1ECE4);
    func_0038B8D8(o, e);
    func_003DF970(e, c + 0x1E7A8);
    *(int *)(e + 4) = func_004F9EC0(&D_00645570, func_004F9E60(&D_00645570, D_00645570.fCC4));
    RaceDisplay__setOrganization(d, o->f6C);
    RaceDisplay__virtual_06(d, 0x12);
    RaceDisplay__virtual_07(d, mode);
}
