typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VE {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

extern "C" void RaceDisplay__render_time(void *arg0);

static inline void vcall(char *o) {
    VE *e = (VE *)(*(char **)(o + 0x14) + 0x28);
    e->fn(o + e->delta);
}

extern "C" void RaceLicenseDisplay__render_time(void *arg0) {
    char *self;
    char *s1;
    char *s0;

    RaceDisplay__render_time(arg0);
    self = (char *)arg0;
    if ((*(s32 *)(self + 0x58) & 0x410) == 0x10) {
        s1 = self + 0x4080;
        s0 = self + 0x3F30;
        s32 n = 2;
        do {
            if (*(s32 *)(self + 0x4380) != 0) {
                if (*(u8 *)s0 != 0) {
                    vcall(s0);
                }
            } else {
                if (*(u8 *)s1 != 0) {
                    vcall(s1);
                }
            }
            n--;
            s1 += 0x94;
            s0 += 0x70;
        } while (n >= 0);

        {
            char *a5 = self + 0x42C8;
            if (*(s32 *)(a5 + 0x6C) > 0) {
                if (*(u8 *)a5 != 0) {
                    vcall(a5);
                }
                a5 = self + 0x4360;
                if (*(u8 *)a5 != 0) {
                    vcall(a5);
                }
            }
        }
    }
}
