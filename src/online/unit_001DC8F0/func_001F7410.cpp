typedef int s32;
struct G {
    char pad[0xF74];
    s32 f74;
};
extern G D_00645570;
extern "C" s32 func_004F68C8(G *g);
extern "C" void func_001F7410(s32 a, s32 b) {
    if (func_004F68C8(&D_00645570))
        D_00645570.f74 = b;
}
