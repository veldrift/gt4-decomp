extern "C" void func_001CD580(char *buf, int c);

struct func_001D2AA8_Obj {
    char pad[0x6A0];
    int state;
};

extern "C" void func_001D2AA8(func_001D2AA8_Obj *self, int k) {
    self->state = k;
    switch (k) {
    case 3:
        return func_001CD580((char *)self + 0x6A4, 0x52);
    case 4:
        return func_001CD580((char *)self + 0x6A4, 0x42);
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    default:
        return func_001CD580((char *)self + 0x6A4, 0);
    }
}
