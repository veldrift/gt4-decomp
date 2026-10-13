typedef int s32;

struct Leaf {
    char pad[0x7C];
    s32 unk7C;
};

struct Inner {
    char pad[0x28];
    Leaf *unk28;
};

struct Obj {
    Inner *unk0;
    char pad4[0x5BC - 0x4];
    Leaf *unk5BC;
};

extern "C" s32 func_004510B0(Obj *arg0) {
    s32 var_v0;
    Leaf *var_v1;
    Leaf *temp_v0;
    Inner *temp_a1;

    temp_a1 = arg0->unk0;
    var_v1 = 0;
    if (temp_a1 != 0) {
        temp_v0 = arg0->unk5BC;
        if (temp_v0 != 0) {
            var_v1 = temp_v0;
        } else {
            var_v1 = temp_a1->unk28;
        }
    }
    var_v0 = 0;
    if (var_v1 != 0) {
        var_v0 = var_v1->unk7C;
    }
    return var_v0;
}
