typedef int s32;
typedef float f32;

struct func_002C1790_arg0 {
    char pad0[0x14];
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
};

extern "C" void mActor__initialize(void);
extern "C" void func_0025B538(s32 c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void mMoveActor__initialize(struct func_002C1790_arg0 *arg0) {
    f32 *temp_v0;
    f32 *temp_a1;
    f32 *temp_v1;

    if (arg0->unk14 != 0) {
        mActor__initialize();
        temp_v0 = &arg0->unk18;
        temp_a1 = &arg0->unk3C;
        if (temp_a1 != temp_v0) {
            temp_a1[0] = temp_v0[0];
            temp_a1[1] = temp_v0[1];
            temp_a1[2] = temp_v0[2];
            temp_a1[3] = temp_v0[3];
        }
        arg0->unk4C = 1.0f;
        temp_v1 = &arg0->unk28;
        if (temp_v1 != temp_v0) {
            temp_v1[0] = temp_v0[0];
            temp_v1[1] = temp_v0[1];
            temp_v1[2] = temp_v0[2];
            temp_v1[3] = temp_v0[3];
        }
        arg0->unk38 = 1.0f;
        func_0025B538(arg0->unk14, temp_a1[0], arg0->unk40, arg0->unk44, arg0->unk48);
    }
}
