typedef signed char s8;

struct Obj {
    char pad0[0x14];
    s8 unk14;
    char pad1[0xB6C - 0x15];
    s8 unkB6C;
    char pad2[0xB8C - 0xB6D];
    s8 unkB8C;
};

extern "C" void func_0042FB48(struct Obj *arg0);

extern "C" void func_0042FB20(struct Obj *arg0) {
    arg0->unkB6C = 0;
    arg0->unkB8C = 0;
    arg0->unk14 = 0;
    func_0042FB48(arg0);
}
