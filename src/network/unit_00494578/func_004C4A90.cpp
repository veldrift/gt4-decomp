/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
struct H { char pad[0xC]; u32 *p; };
extern H *D_006452D4;
extern "C" void func_004C4B98(u32, void *);
static inline u32 rd(u8 *p, int o) {
    u32 x = (p[o] << 24) | p[o+3];
    u32 y = (p[o+2] << 8) | (p[o+1] << 16);
    return x | y;
}
extern "C" int func_004C4A90(u8 *a, int n) {
    u32 t = rd(a, 0);
    if (t != 0 && t != 0xD0000000) return 0x8000445B;
    if (n < 12) return 0x8000445B;
    if (t == 0xD0000000 && rd(a, 4) != (u32)n) return 0x8000445B;
    D_006452D4->p = (u32 *)(a + 8);
    if (t == 0) {
        *D_006452D4->p = 0;
        func_004C4B98(0xD0000000, a);
        func_004C4B98(n, a + 4);
    }
    return 0;
}
