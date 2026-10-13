typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void func_00127E60(void *arg0) {
    u32 pattern = 0x157529FF;
    *(s32 *)((char *)arg0 + 0x0) = 0;
    *(s32 *)((char *)arg0 + 0x46C) = 0;
    *(s32 *)((char *)arg0 + 0x478) = 0;
    *(s32 *)((char *)arg0 + 0x470) = 0;
    *(s32 *)((char *)arg0 + 0x474) = 0;
    *(s32 *)((char *)arg0 + 0x47C) = 0;

    s32 n1 = 2;
    s32 *p = (s32 *)((char *)arg0 + 0x450);
    do {
        n1--;
        *p-- = pattern;
    } while (n1 >= 0);

    s32 *a = (s32 *)((char *)arg0 + 0x394);
    s32 *b = (s32 *)((char *)arg0 + 0x37C);
    u8 *bytes = (u8 *)arg0 + 4;
    s32 n2 = 5;
    do {
        n2--;
        *bytes = 0;
        a[-12] = 0;
        bytes += 0x80;
        *b++ = 0;
        *a++ = 0;
    } while (n2 >= 0);

    u8 *base = (u8 *)arg0;
    *(s32 *)(base + 0x3AC) = 0;
    *(s32 *)(base + 0x3B0) = 0;
    *(u8 *)(base + 0x3B4) = 0;
    *(u8 *)(base + 0x3B5) = 0;
    *(u8 *)(base + 0x3B6) = 0;
    *(s32 *)(base + 0x3B8) = -1;
    *(s32 *)(base + 0x3BC) = -1;
    *(s32 *)(base + 0x3C0) = 0;
    *(u8 *)(base + 0x408) = 0;
    *(s32 *)(base + 0x480) = 0;
    *(s32 *)(base + 0x488) = 0;
    *(s32 *)(base + 0x498) = 0;
    *(s32 *)(base + 0x48C) = 0;
    *(s32 *)(base + 0x490) = 0;
    *(s32 *)(base + 0x494) = 0;
    *(s32 *)(base + 0x4A0) = -1;
    *(s32 *)(base + 0x4A4) = 0;
    *(s32 *)(base + 0x4BC) = -1;
    *(u8 *)(base + 0x4C0) = 0;
    *(s32 *)(base + 0x4D0) = -1;
    *(u8 *)(base + 0x4D4) = 0;
    *(s32 *)(base + 0x4E4) = -1;
    *(s32 *)(base + 0x4E8) = -1;
    *(s32 *)(base + 0x4EC) = 0;
    *(s32 *)(base + 0x3C4) = 0;
    *(s32 *)(base + 0x484) = 0;
    *(s32 *)(base + 0x4B8) = 0;
    *(s32 *)(base + 0x4A8) = 0;
    *(s32 *)(base + 0x49C) = 0;
    *(s32 *)(base + 0x4B0) = 0;
    *(s32 *)(base + 0x4AC) = -1;
    *(s32 *)(base + 0x4B4) = 0;
    *(s32 *)(base + 0x4F0) = 0;
    *(s32 *)(base + 0x4F4) = 0;
}
