/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Pause {
    char pad0[0x34];
    s32 f34;
};

struct Disp {
    char pad0[8];
    char *f8;
};

struct Win {
    char pad0[0x14];
    char *f14;
};

struct Obj {
    char pad0[0xCC8];
    s32 type;
    char pad1[0xE408 - 0xCCC];
    char *eE408;
    char pad2[0xE410 - 0xE40C];
    s32 vE410;
    char pad3[0xE424 - 0xE414];
    Win *eE424;
};

extern "C" void func_0038B7C0(Obj *, void *);
extern "C" void func_0038B8D8(Obj *, void *);
extern "C" void func_0038B990(Obj *, void *);
extern "C" void func_0038BA90(Obj *, s32);
extern "C" void func_0038BAB0(Obj *, void *);
extern "C" void RaceDisplay__virtual_06(void *, s32);
extern "C" void RaceSinglePlayer__initialize(Obj *, s32);
extern "C" void func_003DF970(void *, void *);

extern "C" void RaceArcade__initialize(Obj *self, s32 arg1) {
    func_0038B7C0(self, 0);
    func_0038B8D8(self, 0);
    func_0038BAB0(self, 0);
    func_0038B990(self, 0);
    func_0038BA90(self, 0);
    Disp *d = (Disp *)((char *)self + 0xE440);
    RaceSinglePlayer__initialize(self, arg1);
    {
        s32 t = self->type;
        Pause *o = (Pause *)((char *)self + 0x22C38);
        s32 a3 = 0;
        if ((u32)(t - 2) < 2) {
            func_0038B7C0(self, 0);
            func_0038B8D8(self, 0);
            func_0038BAB0(self, 0);
            func_0038B990(self, 0);
            func_0038BA90(self, 0);
        } else {
            if (t == 1 || t == 3) a3 = 1;
            o->f34 = a3;
            func_0038B7C0(self, (char *)self + 0x22C38);
            func_0038B8D8(self, (char *)self + 0x22738);
            func_003DF970((char *)self + 0x22738, (char *)self + 0x22708);
            func_0038B990(self, self->eE408);
            func_0038BAB0(self, (char *)self + 0x22C70);
            self->eE424->f14 = (char *)self + 0x22708;
            func_0038BA90(self, self->vE410);
        }
    }
    RaceDisplay__virtual_06(d, 1);
    d->f8 = (char *)self + 0x22708;
}
