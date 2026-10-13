typedef int s32;

struct Obj0053DF20Inner {
    char pad0[0xC];
    s32 unkC;
    char pad1[0x203C - 0x10];
    s32 unk203C;
};

struct Obj0053DF20 {
    char pad0[0x44];
    struct Obj0053DF20Inner *unk44;
};

extern "C" void func_0053DF20(struct Obj0053DF20 *arg0, s32 arg1) {
    struct Obj0053DF20Inner *temp;

    if (arg0 != 0) {
        if (arg1 == 0) {
            arg0->unk44->unkC = 8;
        } else {
            temp = arg0->unk44;
            if (temp->unk203C == 0) {
                temp->unk203C = 1;
                temp->unkC = 3;
                return;
            }
            temp->unkC = 8;
        }
    }
}
