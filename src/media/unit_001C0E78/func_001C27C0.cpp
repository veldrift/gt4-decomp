/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct A { char pad0[8]; s32 f8; char padC[4]; s32 f10; s32 f14; char pad18[0x1C]; s32 f34; s32 f38; char pad3C[8]; s32 f44; s32 f48; };
struct B { s32 w; s32 h; s32 stride; char padC[0xC]; u8 *data; };

extern "C" s32 func_001C2388(A *, B *, s32, s32) throw();

extern "C" s32 func_001C27C0(A *a, B *b, s32 x, s32 y) {
    s32 w = b->w - (a->f8 + a->f10);
    s32 h = b->h - (a->f8 + a->f14);
    s32 m;
    u8 *row;
    s32 j;
    if (x >= w) {
        x = 0;
        y++;
    }
    m = a->f38;
    if (m < a->f34) m = a->f34;
    m = m + m / 2;
    row = b->data;
    row += (y + m) * b->stride;
    for (j = y; j < h; j++) {
        s32 xx;
        u8 *p;
        p = row + x + m;
        for (xx = x; xx < w; xx++) {
            if (*p++ != 0 && func_001C2388(a, b, xx, j) != 0) {
                a->f44 = xx;
                a->f48 = j;
                return 1;
            }
        }
        x = 0;
        row += b->stride;
    }
    a->f44 = b->w;
    a->f48 = b->h;
    return 0;
}
