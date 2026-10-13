/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

void *memcpy(void *, const void *, unsigned int);

extern "C" s32 func_0052ADB8(void *arg0, void *arg1) {
    u8 sp[8];
    u8 *src;
    u32 lim;
    u32 sum;

    src = arg0 != 0 ? (u8 *)arg0 + 0x18 : (u8 *)0x10;

    sp[0] = src[0];
    sp[1] = src[1];
    *(u16 *)&sp[0] = *(u16 *)&sp[0] & 0x7FF;

    sp[2] = src[0];
    sp[3] = src[1];
    *(u16 *)&sp[2] = *(u16 *)&sp[2] & 0xF800;

    if (*(u16 *)&sp[2] & 0x6000) {
        *(u16 *)&sp[4] = 4;
    } else {
        *(u16 *)&sp[4] = 2;
    }

    if (arg0 != 0) {
        lim = *(u32 *)arg0;
        sum = (u32)*(u16 *)&sp[4] + (u32)*(u16 *)&sp[0];
        if (sum < lim) {
            memcpy(arg1, (u8 *)arg0 + lim + 4, 4);
            return 0;
        }
    }

    *(s32 *)arg1 = 0;
    return 0;
}
