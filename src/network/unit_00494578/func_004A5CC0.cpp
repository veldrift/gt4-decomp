#include "spr.h"
struct Spr {
    char pad0[0x48];
    union { unsigned short flags; float alias; } word;
    char pad4A[0xAB0 - 0x4C];
    float ab0[4];
    char padAC0[0xAE0 - 0xAC0];
    float ae0[4];
};
enum Property { Color = 0, Enable = 1, Reserved = 2, Material = 3, Mode = 4 };
extern "C" void func_004A5CC0(enum Property which, const float *value) {
    struct Spr *p = (struct Spr *)spr_base();
    switch (which) {
    case 0:
        p->ae0[0] = value[0];
        p->ae0[1] = value[1];
        p->ae0[2] = value[2];
        p->ae0[3] = value[3];
        break;
    case 1:
        if (value[0] != 0.0f) p->word.flags |= 0x40;
        else p->word.flags &= ~0x40;
        break;
    case 2: break;
    case 3:
        p->ab0[0] = value[0];
        p->ab0[1] = value[1];
        p->ab0[2] = value[2];
        p->ab0[3] = value[3];
        p->word.flags |= 2;
        break;
    case 4:
        if (value[0] != 0.0f) p->word.flags |= 0x80;
        else p->word.flags &= ~0x80;
        break;
    default: break;
    }
}
