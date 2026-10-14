/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;

struct Sub {
    char pad0[0x467];
    u8 mode;
    char pad468[0x4B1 - 0x468];
    u8 flags;
    char pad4B2[0x4B8 - 0x4B2];
    u16 f4B8;
    u16 f4BA;
};

extern "C" u8 GetPitStopStatus(char *o) {
    Sub *s = (Sub *)(o + 0x104);
    u8 m = s->mode;
    if (m == 0) return 0;
    if (!(s->flags & 0x10)) return 0;
    if (m == 2) return 1;
    if (m == 4) return 5;
    if (m == 3) {
    int t = s->f4BA;
    if (s->f4BA != 0) {
        if (s->f4BA == 0x2D1) return 1;
        if (t >= 0x285) return 2;
        u8 res = m;
        if (t < 0x3C) res = 4;
        return res;
    }
    u16 w = s->f4B8;
    u8 res = 5;
    if (w != 0) res = 1;
    return res;
    }
    return 0;
}
