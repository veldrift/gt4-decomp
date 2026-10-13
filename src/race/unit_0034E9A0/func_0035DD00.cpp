struct func_0035DD00_sub {
    char pad0[0x466];
    signed char unk466;
    char pad1[0x5C4 - 0x467];
    float unk5C4;
    char pad2[0x5D0 - 0x5C8];
    float unk5D0;
    float unk5D4;
    char pad3[0x6AC - 0x5D8];
    float unk6AC;
};

struct func_0035DD00_arg0 {
    char pad0[0x54C];
    float unk54C;
};

extern "C" float func_00343518(unsigned int *total, float amount);

extern "C" void func_0035DD00(struct func_0035DD00_arg0 *arg0) {
    struct func_0035DD00_sub *s0 = (struct func_0035DD00_sub *)((char *)arg0 + 0x104);
    float f20 = s0->unk5C4;
    float f0;
    float f1;
    float thr;

    if (!(f20 < 0.0f)) {
        f20 = f20 * arg0->unk54C;
        f0 = func_00343518((unsigned int *)((char *)arg0 + 0x6DC), s0->unk5D4 + f20);
        f1 = s0->unk5D0 + f20;
        thr = 0x1.312D00p+26f;
        s0->unk5D4 = f0;
        s0->unk5D0 = f1;
        if (f1 >= thr) {
            s0->unk5D0 = f1 - thr;
        }
        if (s0->unk466 == 1) {
            f0 = s0->unk6AC + f20;
            s0->unk6AC = f0;
            if (f0 >= thr) {
                s0->unk6AC = f0 - thr;
            }
        }
    }
}
