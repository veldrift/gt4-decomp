typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct func_004C3998_entry {
    u8 *base;
    u8 pad4[6];
    u16 a;
    u16 b;
};

extern "C" s32 func_004C3998(u8 *self, u8 idx, u16 j) {
    u32 k4 = (u32)j << 2;
    u32 off = (u32)idx * 16 + 0x50;
    u32 k = (k4 + j) << 2;
    func_004C3998_entry *e = (func_004C3998_entry *)(self + off);
    u32 b = e->b;
    u32 a = e->a;
    u8 *q = e->base + k;
    u32 t = (a + b) * 3;
    q = q + t * 2;
    q = q + 6;
    return q[0xD] - q[7];
}
