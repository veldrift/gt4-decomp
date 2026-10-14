/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern signed char D_006B0C80[];
extern "C" int func_004B95D0(u8 **pp, int adv) {
    u8 *p = *pp;
    u8 c = p[0];
    signed char len = D_006B0C80[c];
    int v = 0;
    switch (len) {
    case 1:
        v = c & 0x7F;
        break;
    case 2:
        v = ((c & 0x1F) << 6) | (p[1] & 0x3F);
        break;
    case 3:
        v = ((c & 0xF) << 12) | ((p[1] & 0x3F) << 6) | (p[2] & 0x3F);
        break;
    }
    if (adv != 0) *pp = p + len;
    return v;
}
