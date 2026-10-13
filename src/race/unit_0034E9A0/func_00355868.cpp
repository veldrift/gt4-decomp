struct func_00355868_inner {
    char pad[0x32];
    unsigned char unk32;
};

struct func_00355868_arg0 {
    char pad0[0x10];
    struct func_00355868_inner *unk10;
    char pad1[0x640 - 0x14];
    float unk640;
    char pad2[0x788 - 0x644];
    float unk788;
    float unk78C;
};

void func_00355868(struct func_00355868_arg0 *arg0) {
    float *p2;
    float *p3;
    float f0;
    float f1;
    float f4;
    float temp;

    p3 = &arg0->unk78C;
    if (arg0->unk10->unk32 == 3) {
        p2 = &arg0->unk788;
        f1 = arg0->unk640;
        if (f1 < 0.0f) {
            f1 = -f1;
        }
        f4 = f1 / 0x1.0AAAA8p+6f;
        if (0x1.0p+0f < f4) {
            f4 = 0x1.0p+0f;
        }
        temp = *p2 + (((f4 * 0x1.199998p+1f) + 0x1.999998p-1f) * 0x1.111110p-6f);
        *p2 = temp;
        if (temp >= 0x1.0p+0f) {
            f0 = (f4 * 0x1.999998p-2f) + 0x1.333332p-1f;
            *p3 = f0;
            *p2 = *p2 - 0x1.0p+0f;
            return;
        }
        *p3 = 0.0f;
    }
}
