typedef int s32;
typedef unsigned char u8;

extern char D_0067A9E8[];
/* Returns this, so the next temporary avoids $v0 as in the original. */
char *func_00379C08(char *self);

void func_0037CDF8(char *arg0) {
    char *a1;

    func_00379C08(arg0);
    a1 = arg0 + 0x2C0;
    *(s32 *)arg0 = (s32)D_0067A9E8;
    *(u8 *)a1 = 0;
    *(u8 *)(a1 + 1) = 0;
    *(s32 *)a1 = *(s32 *)a1 & 0xFF00FFFF;
    *(u8 *)(a1 + 3) = 0;
    *(s32 *)(arg0 + 0x2C4) = -1;
}
