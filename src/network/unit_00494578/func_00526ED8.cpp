typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

/* 12-byte block copied as 8 bytes (ldl/ldr) plus a 4-byte unaligned tail
   (lwl/lwr, swl/swr): kind at +2, index (u16) at +4, value at +8. */
typedef struct {
    char b[12];
} Block12_00526ED8;

extern "C" s32 func_00526ED8(void *arg0, void *unused, void *arg2) {
    Block12_00526ED8 t = *(const Block12_00526ED8 *)arg2;
    s32 base = *(s32 *)((char *)arg0 + 0x88);
    if (base != 0) {
        u8 kind = (u8)t.b[2];
        s32 idx = kind * 3 * 8;
        s32 tab = *(s32 *)((char *)idx + base);
        u16 i = *(u16 *)(t.b + 4);
        s32 *p = *(s32 **)((char *)(i * 4) + tab);
        *(s32 *)((char *)p + 0x40) = *(s32 *)(t.b + 8);
    }
    return 0;
}
