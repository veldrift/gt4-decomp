struct func_00370898_arg0 {
    char pad0[0x80];
    int unk80;
};

extern "C" void func_00370548(void *arg0, void *arg1, int arg2);

extern "C" void func_00370898(struct func_00370898_arg0 *arg0) {
    char *p = (char *)arg0 + 0x44;

    p[1] = 0x18;
    p[0] = 0;
    func_00370548(arg0, (char *)arg0 + 0x60, arg0->unk80);
}
