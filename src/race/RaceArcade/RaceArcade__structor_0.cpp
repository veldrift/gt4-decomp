/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Slot { char b[8]; };

struct Obj {
    char pad0[0x64];
    s32 vt;
    char pad1[0x4];
    s32 p70;
    char pad2[0xD68 - 0x74];
    s32 flag;
    char pad3[0x125C0 - 0xD6C];
    char blk[0x22708 - 0x125C0];
    Slot slots[6];
    char pad4[0x22738 - 0x22738 + 0];
};

extern char RaceArcade__vtable[];
extern "C" int func_0033CF48(void);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" s32 func_00393700(void *);
extern "C" void func_003BAB90(void *);
extern "C" void RacePause__structor_0(void *);
extern "C" void func_003C31C8(void *, int);
extern "C" s32 RaceSinglePlayer__structor_0(void *);
extern "C" void func_003D7700(void *);
extern "C" void func_003D8490(void *, s32);
extern "C" void func_003DCA28(void *);
extern "C" s32 func_003DD4B8(void *, s32);
extern "C" void ResultArcade__structor_0(void *);
extern "C" void func_003DF898(void *, int);

extern "C" int RaceArcade__structor_0(char *self) {
    s32 i = 5;
    char *p = self + 0x22708;
    RaceSinglePlayer__structor_0(self);
    *(char **)(self + 0x64) = RaceArcade__vtable;
    DynamicsConductorSinglePlayer__structor_1(self + 0x125C0);
    do {
        func_00393700(p);
        p += 8;
    } while (--i != -1);
    char *a = self + 0x22738;
    char *b = self + 0x22C38;
    char *c = self + 0x22C70;
    ResultArcade__structor_0(a);
    RacePause__structor_0(b);
    char *d = self + 0x23FB0;
    func_003D7700(c);
    char *e = self + 0x240B8;
    func_003DCA28(d);
    func_003BAB90(e);
    *(char **)(self + 0xE408) = d;
    *(char **)(self + 0xE410) = e;
    *(char **)(self + 0x70) = self + 0x125C0;
    if (func_0033CF48() == 0) {
        s32 k = 0xE350 + (s32)self;
        func_003C31C8(b, k);
        func_003DF898(a, k);
        func_003D8490(c, k);
        func_003DD4B8(d, k);
    }
    *(s32 *)(self + 0xD68) = 1;
}
