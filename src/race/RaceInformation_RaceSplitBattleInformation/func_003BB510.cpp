/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Self {
    char pad[0x11C];
    s32 unk11C;
};
extern "C" s32 func_003BB510(Self *arg0, s32 arg1) {
    s32 v = arg0->unk11C;
    if (v < 0) {
        return 0;
    }
    return v ? v : arg1;
}
