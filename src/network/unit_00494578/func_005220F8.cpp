typedef int s32;
typedef unsigned int u32;

struct Obj005220F8 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

extern "C" s32 func_005220F8(struct Obj005220F8 *arg0) {
    s32 r;

    r = 0;
    if (arg0 != 0) {
        r = arg0->unk0;
        if (r != 0) {
            r = arg0->unk4;
            if (r != 0) {
                if ((u32)arg0->unkC < 4) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
