typedef int s32;

struct P4 {
    char b[4];
};

extern s32 D_0064A564;

extern "C" s32 func_0050FAD8(struct P4 *arg0, s32 arg1) {
    struct P4 t;
    *(s32 *)&t = arg1;
    *arg0 = t;
    D_0064A564 += 1;
    return 4;
}
