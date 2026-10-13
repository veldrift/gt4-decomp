typedef int s32;

struct Node042 {
    char pad0[4];
    struct Node042 *unk4;
    s32 unk8;
};

struct Head042 {
    char pad0[8];
    struct Node042 *unk8;
};

extern "C" struct Node042 *func_00542A28(struct Head042 *arg0, s32 arg1) {
    struct Node042 *v = 0;

    arg1 &= 0x1FFFFFFF;
    if (arg0 != 0) {
        v = arg0->unk8;
    }
    while (v != 0 && v->unk8 != arg1) {
        v = v->unk4;
    }
    return v;
}
