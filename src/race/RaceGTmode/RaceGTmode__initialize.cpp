/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Z { void *a; void *b; void *f8; };
struct Q { char pad[0x14]; void *f14; };
struct P { char pad[0x34]; s32 f34; };
struct U80 { char pad[4]; char *f4; };
struct U6C { char pad[0x70]; s32 f70; char pad74[0xC]; U80 *f80; };
struct Obj {
    char pad0[0x6C]; U6C *u6C;
    char pad70[0xCC8 - 0x70]; s32 cc8;
    char padCCC[0xE408 - 0xCCC]; void *e408; void *e40c; void *e410; char pad414[0x10]; Q *e424;
};
extern "C" void func_0038B7C0(Obj *, void *);
extern "C" void func_0038B8D8(Obj *, void *);
extern "C" void func_0038B990(Obj *, void *);
extern "C" void func_0038BA90(Obj *, void *);
extern "C" void func_0038BAB0(Obj *, void *);
extern "C" void RaceDisplay__virtual_06(Z *, s32);
extern "C" void RaceDisplay__setExternalStartLogo(Z *, s32);
extern "C" void RaceSinglePlayer__initialize(Obj *, s32);
extern "C" void func_003DF970(void *, void *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getRaceLabel(s32);
extern "C" s32 func_00594470(s32, const char *, u32);
extern "C" void RaceGTmode__initialize(Obj *self, s32 arg1) {
    func_0038B7C0(self, 0);
    func_0038B8D8(self, 0);
    Z *s2 = (Z *)((char *)self + 0xE440);
    func_0038BAB0(self, 0);
    func_0038B990(self, 0);
    func_0038BA90(self, 0);
    RaceSinglePlayer__initialize(self, arg1);
    s32 m = self->cc8;
    P *p = (P *)((char *)self + 0x22738);
    s32 flag = 0;
    if ((u32)(m - 2) < 2U) {
        func_0038B7C0(self, 0);
        func_0038B8D8(self, 0);
        func_0038BAB0(self, 0);
        func_0038B990(self, 0);
        func_0038BA90(self, 0);
    } else {
        if (m == 1 || m == 3) flag = 1;
        p->f34 = flag;
        func_0038B7C0(self, (char *)self + 0x22738);
        func_0038B8D8(self, (char *)self + 0x23BCC);
        func_003DF970((char *)self + 0x23BCC, (char *)self + 0x22708);
        func_0038B990(self, self->e408);
        func_0038BAB0(self, (char *)self + 0x22770);
        self->e424->f14 = (char *)self + 0x22708;
        func_0038BA90(self, self->e410);
    }
    RaceDisplay__virtual_06(s2, 1);
    s2->f8 = (char *)self + 0x22708;
    s32 v = SPEC_DATABASE__RaceSpec__getRaceLabel(self->u6C->f70);
    if (v && func_00594470(v, "rh_", 3) == 0) {
        char *x = self->u6C->f80->f4;
        RaceDisplay__setExternalStartLogo(s2, *(s32 *)(x + 0xA8));
    }
}
