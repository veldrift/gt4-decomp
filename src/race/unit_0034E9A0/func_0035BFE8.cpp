typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Sub {
    char pad0[0x4B8];
    u16 flags;
    u16 timer;
    char pad1[0x64E - 0x4BC];
    u8 b64E;
    u8 b64F;
};

struct Info {
    u8 op;
    u8 b1;
    u8 b2;
    u8 b3;
};

extern "C" void func_0035BFE8(char *self, Info *info) {
    Sub *s = (Sub *)(self + 0x104);
    if (info->op == 1) {
        u16 a2 = s->flags;
        if (!(a2 & 0x10))
            return;
        if (a2 & 4) {
            if (info->b1 != 0xFF) {
                u16 v = a2 | 0x40;
                s->flags = v;
                a2 = v;
            }
            if (info->b2 != 0xFF) {
                u16 v = a2 | 0x80;
                s->flags = v;
                a2 = v;
            }
            s->b64E = info->b1;
            s->b64F = info->b2;
        }
        if (a2 & 8) {
            if (info->b3 != 0) {
                u16 v = a2 | 0x100;
                s->flags = v;
                a2 = v;
            }
        }
        u16 v0 = a2 & 0xFFE3;
        s->flags = v0;
        if (v0 == 0)
            s->timer = 0;
    } else if (info->op == 2) {
        u16 f = s->flags;
        if (f & 0x100) {
            u16 v = f ^ 0x100;
            s->flags = v;
            if (!(v & 0xC0))
                s->timer = 0x5A;
        }
    }
}
