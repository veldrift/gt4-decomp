extern "C" void func_00230A50(void *self, float *x, float *y);

struct func_00230ED8_self {
    char pad0[0x6F4];
    float unk6F4;
    char pad6F8[8];
    float unk700;
    char pad704[0x1D40 - 0x704];
    int unk1D40;
};

extern "C" void func_00230ED8(void *arg0, float fparg0, float fparg1) {
    float v[2];
    struct func_00230ED8_self *self = (struct func_00230ED8_self *)arg0;

    v[0] = fparg0;
    v[1] = fparg1;
    if (self->unk1D40 == 0) {
        func_00230A50(arg0, &v[0], &v[1]);
        self->unk6F4 = v[0];
        self->unk700 = v[1];
    }
}
