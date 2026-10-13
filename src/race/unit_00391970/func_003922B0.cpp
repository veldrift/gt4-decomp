typedef int s32;
typedef unsigned char u8;

extern char D_0088F2C0[];
extern "C" void *func_005A48D8(void *, s32, s32);

extern "C" void func_003922B0(s32 arg0) {
    char *p = D_0088F2C0;
    func_005A48D8(p, 0, 0xB);
    if (arg0 & 1) {
        p[0x0] = 1;
    }
    if (arg0 & 2) {
        p[0x1] = 1;
    }
    if (arg0 & 4) {
        p[0x2] = 1;
    }
    if (arg0 & 8) {
        p[0x3] = 1;
    }
    if (arg0 & 0x10) {
        p[0x7] = 1;
    }
    if (arg0 & 0x20) {
        p[0x4] = 1;
    }
    if (arg0 & 0x40) {
        p[0x8] = 1;
    }
    if (arg0 & 0x80) {
        p[0x9] = 1;
    }
    if (arg0 & 0x100) {
        p[0xA] = 1;
    }
    if (arg0 & 0x200) {
        p[0x5] = 1;
    }
    if (arg0 & 0x400) {
        p[0x6] = 1;
    }
}
