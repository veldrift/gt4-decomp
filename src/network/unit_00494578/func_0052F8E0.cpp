struct O {
    int m0, m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C;
};
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" int func_0052F8E0(O *o) {
    if (o == 0) {
        return 0x17;
    }
    func_005A48D8(o, 0, 0x68);
    o->m8 = 1;
    o->mC = 1;
    o->m14 = 0;
    o->m18 = 1;
    o->m1C = 0x10;
    o->m20 = 0x1F40;
    o->m24 = 1;
    o->m0 = 1;
    o->m28 = 0x10;
    o->m2C = 0x1F40;
    o->m10 = 0x9C4;
    return 0;
}
