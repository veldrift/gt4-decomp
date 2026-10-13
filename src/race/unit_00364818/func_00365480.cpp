typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct func_00365480_arg0 {
    char pad0[0x7C];
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
};

struct func_00365480_src {
    char pad0[0x20];
    u8 unk20;
    char pad21[3];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    char pad27[1];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
};

extern "C" void func_00365480(struct func_00365480_arg0 *arg0, int arg1) {
    struct func_00365480_src *src;
    int v;

    if (arg1 != 0) {
        src = (struct func_00365480_src *)((char *)arg0 + 0xF818);
        arg0->unk80 = (f32)src->unk25;
        arg0->unk84 = (f32)src->unk26 * 0x1.4000000000000p+3f;
        arg0->unk7C = (f32)src->unk24 * 0x1.47ae140000000p-7f;
        arg0->unk8C = (f32)src->unk29;
        arg0->unk90 = (f32)src->unk2A * 0x1.4000000000000p+3f;
        arg0->unk88 = (f32)src->unk28 * 0x1.47ae140000000p-7f;
        v = src->unk20;
        if (v == 0) {
            v = 100;
        }
        arg0->unk94 = (f32)v * 0x1.47ae140000000p-7f;
        return;
    }
    arg0->unk94 = 0x1.0000000000000p+0f;
    *(s32 *)&arg0->unk84 = 0;
    *(s32 *)&arg0->unk7C = 0;
    *(s32 *)&arg0->unk8C = 0;
    *(s32 *)&arg0->unk90 = 0;
    *(s32 *)&arg0->unk88 = 0;
    *(s32 *)&arg0->unk80 = 0;
}
