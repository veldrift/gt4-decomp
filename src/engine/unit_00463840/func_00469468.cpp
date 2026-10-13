typedef unsigned char u8;

struct Src {
    char pad0[0x38];
    u8 unk38;
    char pad1[0x6];
    u8 unk3F;
};

struct Dst {
    char pad0[0xA];
    u8 unkA;
    u8 unkB;
};

extern struct Src D_00623FB8;
extern struct Dst D_00623E50;

extern "C" void func_00469468(void) {
    D_00623E50.unkA = D_00623FB8.unk38;
    D_00623E50.unkB = D_00623FB8.unk3F;
}
