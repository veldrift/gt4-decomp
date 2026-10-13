struct Obj {
    char pad0[0x14];
    int unk14;
    char pad18[0x10];
    void *unk28;
};

struct Extra {
    char pad0[0x8];
    float fl[9];
};

extern "C" void func_0021C8D0(void *self, int index, int arg, int extra);

extern "C" void func_0021CF60(Obj *self, int arg1, int arg2, Extra *extra) {
    void *temp = self->unk28;
    if (temp != 0) {
        func_0021C8D0(temp, self->unk14, arg1, arg2);
        float zero = 0.0f;
        extra->fl[0] = zero;
        extra->fl[1] = zero;
        extra->fl[2] = zero;
        extra->fl[3] = zero;
        extra->fl[4] = zero;
        extra->fl[5] = zero;
        extra->fl[6] = zero;
        extra->fl[7] = zero;
        extra->fl[8] = zero;
    }
}
