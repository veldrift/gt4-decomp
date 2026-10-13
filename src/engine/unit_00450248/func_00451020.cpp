typedef int s32;

struct Next {
    char pad[0x7C];
    s32 unk7C;
};

struct Head {
    char pad[0x20];
    Next *unk20;
};

struct Obj {
    Head *unk0;
    char pad4[0x5B4];
    Next *unk5B8;
};

extern "C" s32 func_00451020(Obj *arg0) {
    s32 var_v0;
    Next *var_v1;
    Head *temp_a1;
    Next *temp_v0;

    temp_a1 = arg0->unk0;
    var_v1 = 0;
    if (temp_a1 != 0) {
        temp_v0 = arg0->unk5B8;
        if (temp_v0 != 0) {
            var_v1 = temp_v0;
        } else {
            var_v1 = temp_a1->unk20;
        }
    }
    var_v0 = 0;
    if (var_v1 != 0) {
        var_v0 = var_v1->unk7C;
    }
    return var_v0;
}
