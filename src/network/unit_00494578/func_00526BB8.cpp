typedef int s32;
typedef unsigned char u8;
typedef short s16;

/* 8-byte record copied with ldl/ldr (4-byte aligned):
   kind at +2, value at +4. */
struct Tmp {
    s16 w0;
    u8 kind;
    u8 x;
    s32 val;
};

extern "C" s32 func_00526BB8(void *arg0, void *unused, Tmp *arg2) {
    Tmp t = *arg2;
    s32 base = *(s32 *)((char *)arg0 + 0x88);
    if (base != 0) {
        s32 idx = t.kind * 3 * 8;
        *(s32 *)((char *)idx + base + 0x14) = t.val;
    }
    return 0;
}
