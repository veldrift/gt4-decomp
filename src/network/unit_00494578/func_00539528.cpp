typedef int s32;
typedef unsigned int u32;
struct Tbl { u32 arr[0x271]; s32 idx; };
extern Tbl D_0064B720;
extern u32 D_0064C0E8;
extern u32 D_0064C0EC;
extern u32 D_0064C0F0;
extern "C" void func_005393B0() throw();
extern "C" s32 func_00539528() {
    D_0064B720.idx = D_0064B720.idx + 1;
    if (D_0064B720.idx >= 0x270) {
        func_005393B0();
    }
    u32 v = D_0064C0F0 ^ D_0064B720.arr[D_0064B720.idx];
    u32 a = D_0064C0E8;
    u32 c = ((a << 25) | (a >> 7)) ^ v;
    u32 b = ((v << 7) | (v >> 25)) ^ D_0064C0EC;
    D_0064C0E8 = c;
    D_0064C0EC = b;
    D_0064C0F0 = (c & v) | (b & ~v);
    return (c & v) | (b & ~v);
}
