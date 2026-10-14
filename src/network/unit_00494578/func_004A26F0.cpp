#include "spr.h"
typedef unsigned long u64;
struct Scratch {
    char pad0[0x1a0];
    u64 mode;
    char pad1[0x30];
    u64 flags;
    char pad2[0xf0];
    int value;
    char spare;
    unsigned char enabled;
};
extern "C" unsigned char D_00629DD8[];
extern "C" int func_004A26F0(int i)
{
    unsigned char value = D_00629DD8[i];
    Scratch *s = (Scratch *)spr_base();
    u64 mode = (u64)(value & 3) << 17;
    s->value = value;
    if (s->enabled) {
        u64 oldmode = s->mode;
        u64 flags = s->flags;
        oldmode &= ~0x60000UL;
        flags |= 0x400040UL;
        oldmode |= mode;
        s->flags = flags;
        s->mode = oldmode;
    }
}
