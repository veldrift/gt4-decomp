/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 D_008A1610[];
u16 func_00552C00(u32 arg0, u32 arg1) {
    u16 *p = (u16 *)((char *)D_008A1610 + ((arg1 & 0xFFFF) << 2));
    return arg0 & 0x22 ? p[1] : p[0];
}
