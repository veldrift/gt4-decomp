typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

struct Sub {
    char pad0[0x467];
    u8 mode;
    char pad468[0x4B8 - 0x468];
    u16 flags;
};

extern "C" int func_0035BD10(Sub *s, s8 *a, s8 *b, s8 *c) {
    s = (Sub *)((char *)s + 0x104);
    unsigned t = s->mode;
    if (t == 4) {
        *a = 0;
        *b = 0;
        *c = 0;
        return 1;
    }
    t += 0xFE;
    t &= 0xFF;
    if (t >= 2) return 0;
    {
        unsigned f = s->flags;
        if (f & 0x11) {
            if (f & 4) {
                *a = 1;
                *b = 1;
            } else if (f & 2) {
                *a = 1;
                *b = 1;
            } else {
                *a = 0;
                *b = 0;
            }
            if (f & 8) {
                *c = 1;
            } else if (f & 2) {
                *c = 1;
            } else {
                *c = 0;
            }
        } else {
            if (f & 0x40) {
                *a = 2;
            } else {
                *a = 0;
            }
            if (f & 0x80) {
                *b = 2;
            } else {
                *b = 0;
            }
            if (f & 0x100) {
                *c = 2;
            } else {
                *c = 0;
            }
        }
        unsigned m = s->mode;
        if (m == 2) return 2;
        return (m == 3) ? 3 : 0;
    }
}
