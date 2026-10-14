typedef unsigned char u8;
typedef unsigned short u16;
union U { u16 h; u8 b[2]; };
struct Raw { char b[4]; };
struct Loc { U lo, hi; u16 size; int copy; };
extern "C" int func_0052AE68(char *self, int value) {
    Loc l;
    l.copy = value;
    u8 *p = self ? (u8 *)(self + 0x18) : (u8 *)0x10;
    l.lo.b[0] = p[0];
    l.lo.b[1] = p[1];
    l.lo.h &= 0x7ff;
    l.hi.b[0] = p[0];
    l.hi.b[1] = p[1];
    l.hi.h &= 0xf800;
    if (l.hi.h & 0x6000) l.size = 4;
    else l.size = 2;
    if (self) {
        unsigned n = *(unsigned *)self;
        if ((unsigned)(l.size + l.lo.h) < n) {
            *(Raw *)(self + n + 4) = *(Raw *)&l.copy;
        }
    }
    return 0;
}
