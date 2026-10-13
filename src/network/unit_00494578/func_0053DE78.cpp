typedef int s32;
typedef long long s64;

struct Func0053DE78Sub {
    char pad0[0xC];
    s32 unkC;
    char pad1[0x203C - 0x10];
    s32 unk203C;
};

struct Func0053DE78Obj {
    char pad0[0x44];
    struct Func0053DE78Sub *unk44;
};

extern "C" void func_0053DE78(struct Func0053DE78Obj *arg0, s32 arg1, s32 arg2, s64 arg3) {
    s64 sp0 = arg3;
    struct Func0053DE78Sub *temp_a0;

    (void)arg2;
    (void)&sp0;
    if (arg0 != 0) {
        if (arg1 == 0) {
            arg0->unk44->unkC = 6;
        } else {
            temp_a0 = arg0->unk44;
            if (temp_a0->unk203C == 0) {
                temp_a0->unk203C = 1;
                temp_a0->unkC = 3;
                return;
            }
            temp_a0->unkC = 8;
        }
    }
}
