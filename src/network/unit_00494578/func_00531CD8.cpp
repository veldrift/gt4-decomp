typedef int s32;
typedef unsigned int u32;

struct Obj00531CD8 {
    char pad0[0x144];
    s32 unk144;
};

extern s32 D_008686B8[];

extern "C" s32 func_00531CD8(s32 *arg0, struct Obj00531CD8 *arg1) {
    s32 *p;
    u32 i;

    if (arg0 == 0) {
        return 0x17;
    }
    if (arg1 != 0) {
        p = D_008686B8;
        for (i = 0; i < 4; i++, p++) {
            if ((s32)arg1 == *p) {
                *arg0 = arg1->unk144;
                return 0;
            }
        }
    }
    *arg0 = 0;
    return 0x17;
}
