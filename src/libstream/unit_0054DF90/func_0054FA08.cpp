typedef int s32;

struct Src {
    s32 w0;
    s32 w4;
};

struct Dst {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

extern "C" s32 D_0064C4C0;

extern "C" s32 func_0054FA08(Dst *arg0, Src *arg1) {
    s32 a3 = arg1->w0;
    s32 a2 = arg1->w4;

    arg0->unk18 = a3;
    arg0->unk1C = a2;
    arg0->unk20 = (a3 >> 4) * (a2 >> 4);
    D_0064C4C0 = 0;
    return 0;
}
