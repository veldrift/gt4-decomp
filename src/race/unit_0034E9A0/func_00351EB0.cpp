typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

struct Sub {
    char pad0[0x462];
    s8 unk462;
    char pad463[0x494 - 0x463];
    f32 unk494;
    char pad498[0x4BA - 0x498];
    u16 unk4BA;
    char pad4BC[0x520 - 0x4BC];
    u8 unk520;
    u8 unk521;
    s8 unk522;
    char pad523[0x53C - 0x523];
    f32 unk53C;
};

struct Obj {
    char pad0[0x10];
    char *unk10;
    char pad14[0xF0];
    struct Sub sub;
};

extern "C" void func_0036BEB8(struct Obj *arg0, s32 arg1);
extern "C" s32 func_003F1F98(struct Obj *arg0);

extern "C" void func_00351EB0(struct Obj *arg0) {
    s32 var_a1;
    u8 temp_v1;
    f32 temp_f2;
    struct Sub *s0;

    var_a1 = -1;
    s0 = &arg0->sub;
    temp_v1 = s0->unk520;
    if (s0->unk4BA != 0) {
        if (temp_v1 != 1) {
            var_a1 = 1;
        }
    } else if (s0->unk462 != 0) {
        if (temp_v1 != 0) {
            var_a1 = 0;
        }
    } else {
        temp_f2 = s0->unk53C;
        if ((temp_f2 > 0x1.1C71C6p-2f) || (s0->unk494 > 0.0f)) {
            if (temp_v1 == 0) {
                var_a1 = 1;
            }
        } else if (temp_f2 < -0x1.1C71C6p-2f) {
            var_a1 = (temp_v1 != 0) ? 0 : -1;
        }
    }
    if (var_a1 != -1) {
        func_0036BEB8(arg0, var_a1);
        if (func_003F1F98((struct Obj *)(arg0->unk10 + 0x234)) != 0) {
            s0->unk522 = 2;
        }
    }
}
