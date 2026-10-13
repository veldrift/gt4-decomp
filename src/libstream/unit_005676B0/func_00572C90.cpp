typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern "C" u32 D_00655358[];

extern "C" s32 func_00572C90(u8 *data, s32 len) {
    u8 *p = data;
    u32 *tbl = D_00655358;
    u8 *end = data + len;
    u32 crc = 0xFFFFFFFF;

    if (len != 0) {
        do {
            u8 c = *p;
            p++;
            crc = tbl[(crc ^ c) & 0xFF] ^ (crc >> 8);
        } while (p != end);
    }
    return ~crc;
}
