typedef int s32;
typedef float f32;

struct func_0024A250_arg0 {
    char pad0[0x110];
    s32 unk110;
};

extern "C" s32 func_0024A250(struct func_0024A250_arg0 *arg0, f32 fparg0) {
    if (arg0->unk110 != 0) {
        return (s32)((fparg0 * 0.5f) * 60.0f);
    }
    return (s32)(fparg0 * 60.0f);
}
