typedef int s32;
typedef unsigned char u8;

s32 func_003683A8(s32 *arg0);

struct D_func_00368420_blk {
    char pad[8];
    u8 b8;
};

s32 func_00368420(char *arg0, char *arg1) {
    if (func_003683A8((s32 *)arg0) != 0) {
        struct D_func_00368420_blk *p = (struct D_func_00368420_blk *)(arg0 + 0x788);
        arg1[0] = p->b8 & 1;
        arg1[1] = (p->b8 >> 1) & 3;
        arg1[2] = (p->b8 >> 3) & 1;
        arg1[3] = (p->b8 >> 4) & 3;
        return 1;
    }
    return 0;
}
