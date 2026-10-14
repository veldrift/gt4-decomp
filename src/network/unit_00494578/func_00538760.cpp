extern char *D_0064B70C;
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void *func_00538760(int type, char *src) {
    if (type == -1) {
        if (src) return func_005A4724(D_0064B70C + 0x104, src, 0x80);
        return func_005A48D8(D_0064B70C + 0x104, (int)src, 0x80);
    }
    if (type == (int)0x80000000) {
        if (src) return func_005A4724(D_0064B70C + 4, src, 0x80);
        return func_005A48D8(D_0064B70C + 4, (int)src, 0x80);
    }
    if (src) return func_005A4724(D_0064B70C + 0x84, src, 0x80);
    return func_005A48D8(D_0064B70C + 0x84, (int)src, 0x80);
}
