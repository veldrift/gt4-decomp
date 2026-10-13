typedef int s32;
typedef signed char s8;

struct Blk_00504BB8;

extern "C" {
s32 func_00504B40(s32 arg0);                    /* solved: int func_00504B40(int arg0) */
void func_00504BB8(const struct Blk_00504BB8 *arg0); /* solved: void func_00504BB8(const Blk_00504BB8 *arg0) */
extern void (*D_008A015C)(char *a, s32 b);
extern s32 D_008A0124;

s32 func_00504F00(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    if (*(s8 *)(arg3 + 0x15) == 0) {
        func_00504B40((s32)(arg3 + 0x90));
        func_00504BB8((const struct Blk_00504BB8 *)(arg3 + 0x1C));
    }
    if (D_008A015C != 0) D_008A015C(arg3, D_008A0124);
    return 0xB4;
}
}
