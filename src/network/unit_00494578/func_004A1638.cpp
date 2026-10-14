/* compiler: ee-gcc2.96-nogcse */
#include "spr.h"
typedef int s32; typedef signed char s8; typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef long s64; typedef unsigned long u64;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void func_004A1950(int);
extern "C" void func_004A2E98(void *);
extern "C" void func_004ABB00(void *);
extern "C" void func_004A1638(u32 arg0) {
    char *p = (char *)spr_base();
    s32 var_a1;

    switch (arg0) {
    case 0: return;
    case 0x1:
        if (M2C_FIELD(p, s64 *, 0x2C0) & (0xFFFFul << 16)) func_004A1950(0);
        M2C_FIELD(p, s8 *, 0x2C4) = 0;
        return;
    case 0x4:
        M2C_FIELD(p, s64 *, 0x1A0) |= 1;
        M2C_FIELD(p, s64 *, 0x1D8) |= 0x400040;
        return;
    case 0x3:
        M2C_FIELD(p, s64 *, 0x1A0) |= 0x4000;
        M2C_FIELD(p, s64 *, 0x1D8) |= 0x400040;
        return;
    case 0x5: {
        struct X { u64 pad:16, enabled:1, mode:2, rest:45; };
        struct Y { u64 pad:32, flag:1, rest:31; };
        struct S { char pad0[0x188]; Y y; char pad1[0x10]; X x; char pad2[0x30]; u64 z; char pad3[0xf0]; u32 mode; u8 flag; s8 enable; };
        S *q = (S *)p;
        q->enable = 1;
        q->x.mode = q->mode;
        q->y.flag = q->flag;
        q->x.enabled = 1;
        q->z |= 0x480048;
        return;
    }
    case 0x6:
        M2C_FIELD(p, u16 *, 0x4A) = (u16) (M2C_FIELD(p, u16 *, 0x4A) | 0x40);
        return;
    case 0x8:
        M2C_FIELD(p, u16 *, 0x4A) = (u16) (M2C_FIELD(p, u16 *, 0x4A) | 0x20);
        return;
    case 0x9:
        M2C_FIELD(p, u16 *, 0x4A) = (u16) (M2C_FIELD(p, u16 *, 0x4A) | 0x80);
        return;
    case 0x2:
        M2C_FIELD(p, u16 *, 0x4A) = (u16) (M2C_FIELD(p, u16 *, 0x4A) | 0x10);
        return;
    case 0x7:
        M2C_FIELD(p, s64 *, 0x130) = (s64) (M2C_FIELD(p, s64 *, 0x130) | 1);
        M2C_FIELD(p, s64 *, 0x1D8) = (s64) (M2C_FIELD(p, s64 *, 0x1D8) | (0x8000ul << 0x13));
        return;
    case 0xA:
        M2C_FIELD(p, s8 *, 4) = 1;
        return;
    case 0xB:
        M2C_FIELD(p, s8 *, 5) = 1;
        return;
    case 0xC:
        M2C_FIELD(p, s64 *, 0x120) = (s64) (M2C_FIELD(p, s64 *, 0x120) | 1);
        M2C_FIELD(p, s64 *, 0x1D8) = (s64) (M2C_FIELD(p, s64 *, 0x1D8) | (0x8000ul << 0x11));
        return;
    case 0xD:
        M2C_FIELD(p, s8 *, 6) = 1;
        return;
    case 0x64:
        M2C_FIELD(p, u16 *, 0x48) = (u16) (M2C_FIELD(p, u16 *, 0x48) | 0x8000);
        return;
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
        M2C_FIELD((((arg0 - 0x65) * 0xD0) + (unsigned int)p), s8 *, 0x3E8) = 1;
        M2C_FIELD(p, u16 *, 0x48) = (u16) (M2C_FIELD(p, u16 *, 0x48) | 1);
        return;
    case 0xE:
        M2C_FIELD(p, s8 *, 8) = 1;
        return;
    case 0xF:
        M2C_FIELD(p, s8 *, 0xB) = 1;
        return func_004ABB00(p);
    case 0x11:
        M2C_FIELD(p, s8 *, 9) = 1;
        return func_004ABB00(p);
    case 0x12:
        M2C_FIELD(p, s8 *, 0xA) = 1;
        return func_004A2E98(p);
    case 0x10:
        M2C_FIELD(p, s8 *, 0xC) = 1;
        return;
    case 0x14:
        M2C_FIELD(p, s8 *, 0xD) = 1;
        return;
    case 0x13:
        M2C_FIELD(p, s8 *, 0xE) = 1;
        M2C_FIELD(p, s8 *, 0) = 1;
        return;
    case 0x15:
        M2C_FIELD(p, s8 *, 0xF) = 1;
        return;
    case 0x16:
        M2C_FIELD(p, s8 *, 0x10) = 1;
        M2C_FIELD(p, s8 *, 0x11) = 0;
        M2C_FIELD(p, s8 *, 0x12) = 1;
        M2C_FIELD(p, s8 *, 0x13) = 0x30;
        return;
    case 0x17:
        M2C_FIELD(p, s8 *, 0x10) = 1;
        M2C_FIELD(p, s8 *, 0x12) = 0;
        M2C_FIELD(p, s8 *, 0x11) = 1;
        M2C_FIELD(p, s8 *, 0x13) = -0x80;
        /* fallthrough */
    default:
        return;
    }
}
