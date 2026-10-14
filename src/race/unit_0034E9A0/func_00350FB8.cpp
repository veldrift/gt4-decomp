typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern "C" float func_00350E28(void *);
extern "C" int func_003F1F98(void *);

struct Inner { char pad[0x2C]; u16 u2C; };
struct Obj0 { char pad[0x10]; char *p10; };
struct S {
    char pad0[0x442];
    u8 b442;
    char pad1[0x466 - 0x443];
    signed char b466;
    u8 b467;
    char pad2[0x494 - 0x468];
    float f494;
    char pad3[0x4FA - 0x498];
    s16 s4FA;
    float f4FC;
    char pad5[0x50C - 0x500];
    float f50C, f510, f514;
    char pad6[0x520 - 0x518];
    u8 b520;
    char pad7;
    u8 b522;
    char pad8[0x53C - 0x523];
    float f53C;
};

extern "C" void func_00350FB8(char *self) {
    S *s = (S *)(self + 0x104);
    Inner *a0 = (Inner *)(*(char **)(self + 0x10) + 0x234);
    switch (s->b522) {
    case 0:
        if (s->f514 != 0.0f) {
            float f = s->f53C;
            if ((f > 0x1.638e36p+1f && s->b520 != 0) || (f < -0x1.638e36p+1f && s->b520 == 0)) {
                if (s->f494 > 0.25f) s->b522 = 2;
            } else {
                if (a0->u2C < s->s4FA) s->b522 = 2;
                else s->f514 = 0.0f;
            }
        }
        break;
    case 1:
        if (s->f514 == 0.0f) {
            s->b522 = 0;
        } else if (func_003F1F98(a0)) {
            s->f510 = func_00350E28(self);
        }
        break;
    }
    if ((u8)(s->b522 - 2) < 2) {
        u8 v = 0;
        if (s->b466 != 1 && s->b467 == 0) v = s->b442;
        s->f50C = s->f4FC;
        float r = func_00350E28(self);
        s->f510 = r;
        if (v != 3 && v != 6 && s->b522 == 3) {
            if (r < s->f50C) {
                s->f494 = 0.0f;
                return;
            }
            s->f494 = 1.0f;
        }
    }
}
