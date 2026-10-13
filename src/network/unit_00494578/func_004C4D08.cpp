typedef unsigned short u16;
typedef unsigned int u32;

extern u16 D_006BA21E[];

extern "C" u16 func_004C4D08(u32 arg0) {
    u32 a = arg0 & 0xFF;
    if (a == 0) return 0;
    if (a == 1) return 0xA1BC;
    if (((a + 0xFE) & 0xFF) < 0x53) return (u16)((0xA49F + a) & 0xFFFF);
    if (a < 0x55) return D_006BA21E[a];
    return 0xFFFF;
}
