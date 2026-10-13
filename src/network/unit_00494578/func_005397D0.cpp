typedef int s32;
typedef unsigned char u8;

#define NULL 0

struct func_00539AD0_arg0 {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_00539AD0(struct func_00539AD0_arg0 *arg0);

extern "C" s32 func_005397D0(u8 *arg0) {
    s32 r;

    if (arg0 == NULL) {
        return 2;
    }
    if (*arg0 != 1) {
        return 2;
    }
    r = func_00539AD0((struct func_00539AD0_arg0 *)arg0);
    if (r == 0) {
        *arg0 = 0;
    }
    return r;
}
