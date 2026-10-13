typedef int s32;

extern "C" {
extern char D_0086F940[];
extern char D_0086FC80[];
void func_00576788(s32 a0);                         /* extern */
void func_005767C0(s32 a0);                         /* extern */
}

/* 40-byte block copied as 4-byte-aligned data (ldl/ldr pairs). */
struct Blk40 {
    char b[36];
    s32 w;
};

extern "C" void func_00551B38(s32 arg0, char *arg1) {
    char *s0 = D_0086FC80 + arg0 * 0x6C;
    func_00576788((s32)D_0086F940);
    *(s32 *)(s0 + 0x40) = 2;
    *(Blk40 *)(s0 + 0x44) = *(Blk40 *)arg1;
    func_005767C0((s32)D_0086F940);
}
