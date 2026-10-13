typedef int s32;

struct Obj0053DE18Inner {
    char pad0[0xC];
    s32 unkC;
    char pad1[0x203C - 0x10];
    s32 unk203C;
};

struct Obj0053DE18 {
    char pad0[0x44];
    struct Obj0053DE18Inner *unk44;
};

extern "C" void func_0053DE18(struct Obj0053DE18 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Obj0053DE18Inner *temp;

    if (arg0 != 0) {
        if (arg1 == 0) {
            if (arg3 == 2) {
                arg0->unk44->unkC = 5;
                return;
            }
        }
        temp = arg0->unk44;
        if (temp->unk203C == 0) {
            temp->unk203C = 1;
            temp->unkC = 3;
            return;
        }
        temp->unkC = 8;
    }
}
