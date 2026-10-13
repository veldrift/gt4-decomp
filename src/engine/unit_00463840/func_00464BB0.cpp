struct func_00464BB0_arg0 {
    char pad0[0x30];
    float unk30;
    char pad34[0xB4];
    void *unkE8;
};

struct func_00464BB0_inner {
    char pad0[0x54C];
    float unk54C;
};

struct func_00464BB0_ret {
    char pad0[0x60];
    float unk60;
};

extern "C" int func_00463BB8(struct func_00464BB0_arg0 *arg0);

void func_00464BB0(struct func_00464BB0_arg0 *arg0, float fparg0) {
    float var;
    float temp_f0;
    float temp_f1;
    float temp_f20;
    struct func_00464BB0_ret *ret;

    temp_f20 = ((struct func_00464BB0_inner *)arg0->unkE8)->unk54C;
    ret = (struct func_00464BB0_ret *)func_00463BB8(arg0);
    temp_f1 = arg0->unk30;
    temp_f0 = ret->unk60 * temp_f20;

    if (temp_f1 < fparg0) {
        var = temp_f1 + temp_f0;
        arg0->unk30 = var;
        if (fparg0 < var) {
            arg0->unk30 = fparg0;
        }
    } else if (fparg0 < temp_f1) {
        var = temp_f1 - temp_f0;
        arg0->unk30 = var;
        if (var < fparg0) {
            arg0->unk30 = fparg0;
        }
    }
}
