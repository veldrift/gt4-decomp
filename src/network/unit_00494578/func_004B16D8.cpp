typedef int s32;

struct S {
    char pad0[0xB0];
    s32 unkB0;
};

extern "C" void func_004AD7A8(void) throw();
extern "C" void func_004B15B8(void) throw();

extern "C" void func_004B16D8(struct S *arg0) {
    struct S *s0 = arg0;
    func_004AD7A8();
    if (s0->unkB0 != 0) {
        func_004B15B8();
    }
}
