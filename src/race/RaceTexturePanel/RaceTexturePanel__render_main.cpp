/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct Texture;
struct Self {
    char pad0[1];
    u8 unk1;
    u8 unk2;
    char pad3;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    float unkC;
    Texture *unk10;
    char pad14[4];
    s32 unk18;
};
extern "C" void func_003AEF18(Texture *t, u8 a, u8 b, float x, float y);
extern "C" void func_003AF108(Texture *t, u8 a, u8 b, float x, float y, float z, float w);
extern "C" s32 func_003AFEC8(s32 a, float f);
extern "C" void func_004AA168(s32);

extern "C" int RaceTexturePanel__render_main(Self *arg0) {
    if (arg0->unk10 != 0) {
        func_004AA168(func_003AFEC8(arg0->unk18, arg0->unkC));
        if (arg0->unk8 == 0 || arg0->unkA == 0) {
            func_003AEF18(arg0->unk10, arg0->unk1, arg0->unk2, (float)arg0->unk4, (float)arg0->unk6);
        } else {
            func_003AF108(arg0->unk10, arg0->unk1, arg0->unk2, (float)arg0->unk4, (float)arg0->unk6, (float)arg0->unk8, (float)arg0->unkA);
        }
    }
}
