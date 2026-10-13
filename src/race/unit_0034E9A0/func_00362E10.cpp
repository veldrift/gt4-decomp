typedef signed char s8;
typedef int s32;

struct func_00362E10_obj {
    char pad0[0x442];
    s8 unk442;
    char pad1[0x23];
    s8 unk466;
};

extern "C" void func_00362E10(struct func_00362E10_obj *o, s32 arg1) {
    s32 v = o->unk466;

    if (v != 2) {
        if (v < 3) {
            if (v >= 0) {
                o->unk442 = arg1;
            }
        } else {
            if (v == 4) {
                o->unk442 = arg1;
            }
        }
    } else {
        o->unk442 = 0;
    }
}
