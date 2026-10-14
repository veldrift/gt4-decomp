/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;

struct Blk {
    char d[64];
};
struct Ctx {
    char b[0x54];
    u32 unk54;
    u32 lo;
    u32 hi;
};

extern "C" {
void *func_005A4724(void *, const void *, u32);
void func_006C5400(Ctx *);
void func_006C7350(Ctx *, int, u32);
}

extern "C" void *func_00546E00(Ctx *c, const u8 *p, u32 len)
{
    u32 old = c->lo;
    u32 idx;

    c->lo = old + len * 8;
    if (c->lo < old) {
        c->hi = c->hi + 1;
    }
    idx = (old >> 3) & 0x3F;
    c->hi = c->hi + (len >> 29);
    if (idx != 0) {
        u8 *dst = (u8 *)c + idx;
        idx = 64 - idx;
        if (len < idx) {
            return func_005A4724(dst, p, len);
        }
        func_005A4724(dst, p, idx);
        p += idx;
        len -= idx;
        func_006C7350(c, 0x40, c->unk54);
        func_006C5400(c);
    }
    while (len >= 64) {
        len -= 64;
        *(Blk *)c = *(const Blk *)p;
        p += 64;
        func_006C7350(c, 0x40, c->unk54);
        func_006C5400(c);
    }
    return func_005A4724(c, p, len);
}
