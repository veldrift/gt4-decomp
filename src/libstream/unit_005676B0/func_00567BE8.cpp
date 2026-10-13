/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;

struct Obj_00567BE8 {
    char *data;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" s32 func_00567BE8(Obj_00567BE8 *arg0) {
    s32 a1 = arg0->unk8;
    s32 a2 = arg0->unkC;
    char *p;

    if (arg0->unk4 < (a1 << 3) + a2 + 1) {
        arg0->unk14 = 1;
    }
    if (arg0->unk14 != 0) {
        return 0;
    }
    p = arg0->data;
    return ((s8)p[a1] >> (7 - a2)) & 1;
}
