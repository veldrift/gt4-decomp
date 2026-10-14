struct Obj {
    char pad[0x1670];
    int field1670;
    int field1674;
};

extern "C" void func_003B1028(void *);
extern "C" void func_00451200(void *);

extern "C" void RaceCarModel__virtual_04(Obj *arg0) {
    func_00451200((char *)arg0 + 0x18);
    if (arg0->field1670 != 0) {
        func_003B1028((char *)arg0 + 0x5E0);
        if (arg0->field1674 != 0) {
            func_003B1028((char *)arg0 + 0xE20);
        }
    }
}
