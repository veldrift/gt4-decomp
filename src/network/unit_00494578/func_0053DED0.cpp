typedef int s32;

struct Func0053DED0Sub {
    char pad0[0xC];
    s32 unkC;
    char pad1[0x203C - 0x10];
    s32 unk203C;
};

struct Func0053DED0Obj {
    char pad0[0x44];
    struct Func0053DED0Sub *unk44;
};

extern "C" void func_0053DED0(struct Func0053DED0Obj *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg1 == 0) {
            arg0->unk44->unkC = 7;
        } else {
            struct Func0053DED0Sub *temp_a0 = arg0->unk44;
            if (temp_a0->unk203C == 0) {
                temp_a0->unk203C = 1;
                temp_a0->unkC = 3;
                return;
            }
            temp_a0->unkC = 8;
        }
    }
}
