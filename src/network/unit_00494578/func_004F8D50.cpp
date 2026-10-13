typedef int s32;

extern "C" {
void func_00576788(s32 a0);                         /* extern */
void func_005767C0(s32 a0);                         /* extern */
}

/* 44-byte block at 0x2154 of the source object, copied as 4-byte-aligned data (ldl/ldr pairs). */
struct Blk44 {
    char b[40];
    s32 w;
};

extern "C" s32 func_004F8D50(char *arg0, char *arg1) {
    char *s0 = arg0 + 8;
    s32 r = 0;

    func_00576788((s32)s0);
    if (*(s32 *)(arg0 + 0x2150) != 0x00FFFFFF) {
        *(s32 *)(arg0 + 0x2150) = 0x00FFFFFF;
        r = 1;
        *(Blk44 *)arg1 = *(Blk44 *)(arg0 + 0x2154);
    }
    func_005767C0((s32)s0);
    return r;
}
