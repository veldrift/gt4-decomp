struct Obj {
    char pad[0x1670];
    int field1670;
    int field1674;
};

extern "C" void func_003B15B8(void *);

extern "C" void RaceCarModel__virtual_31(Obj *arg0) {
    if (arg0->field1670 != 0) {
        func_003B15B8((char *)arg0 + 0x5E0);
        if (arg0->field1674 != 0) {
            func_003B15B8((char *)arg0 + 0xE20);
        }
    }
}
