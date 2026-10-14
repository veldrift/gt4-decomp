/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long s64;
struct Entry { u8 *base; u8 pad[6]; u16 a,b; };
struct Self { u8 pad[0x24]; u8 *base; };
extern "C" int func_004C3918(Self *self, u8 idx, u16 j) {
    u32 off = (u32)idx * 16 + 0x50;
    u32 k4 = (u32)j << 2;
    u32 k = (k4 + j) << 2;
    Entry *e = (Entry *)(self->base + off);
    u32 b = e->b;
    u32 a = e->a;
    u8 *q = e->base;
    u32 t = (a + b) * 3;
    q = q + t * 2;
    q = q + 0x14;
    q = q + k;
    return (int)(((s64)q[0]<<24) | q[3] | (((s64)q[2]<<8) | ((s64)q[1]<<16)));
}
