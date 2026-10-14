/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct Par {
    char pad[0x462];
    u8 f462;
    char pad1[0x468 - 0x463];
    f32 f468;
    char pad2[0x488 - 0x46C];
    f32 f488;
    char pad3[0x494 - 0x48C];
    f32 f494;
    char pad4[0x526 - 0x498];
    u8 f526;
};
struct Car {
    char pad[0x104];
    Par p;
};
struct Car2 { char pad[0x54C]; f32 dt; };
struct Obj {
    char pad[0x14];
    f32 f14;
    char pad1[0x1E - 0x18];
    u8 f1E;
    char pad2[0x30 - 0x1F];
    f32 f30;
    f32 f34;
    f32 f38;
    s16 f3C;
    u8 f3E;
    char pad3[0xE8 - 0x3F];
    char *fE8;
};
struct Gl {
    u8 f0;
    char pad[0x24 - 1];
    f32 f24;
    char pad2[0x44 - 0x28];
    f32 f44;
};

extern "C" Gl D_00623E50;
extern "C" void func_00343D60(void *, f32);

extern "C" void func_00464F38(Obj *o) {
    char *a = o->fE8;
    Par *p = (Par *)(a + 0x104);
    f32 dt;
    f32 r;
    if (D_00623E50.f0 != 0) {
        f32 v = o->f14;
        f32 x = p->f488;
        v = v + ((D_00623E50.f24 * (o->f34 - x) - D_00623E50.f44 * v) * ((Car2 *)a)->dt);
        f32 nx = x + v * ((Car2 *)a)->dt;
        p->f488 = nx;
        if (nx > 1.0f) {
            p->f488 = 1.0f;
            v = 0.0f;
        } else if (nx < 0.0f) {
            p->f488 = 0.0f;
            v = 0.0f;
        }
        o->f14 = v;
        r = p->f488;
    } else {
        r = o->f34;
        if ((u8)(o->f1E - 1) < 2) {
            f32 cur = p->f488;
            f32 tgt = r;
            dt = ((Car2 *)a)->dt;
            if (cur < tgt) {
                r = cur + dt;
                if (tgt < r)
                    r = tgt;
            } else {
                r = cur - dt;
                if (r < tgt)
                    r = tgt;
            }
        }
        p->f488 = r;
    }
    p->f494 = r;
    p->f468 = o->f30;
    func_00343D60(a, o->f38);
    p->f462 = o->f3E;
    if (o->f3C != 0)
        p->f526 = (u8)o->f3C;
}
