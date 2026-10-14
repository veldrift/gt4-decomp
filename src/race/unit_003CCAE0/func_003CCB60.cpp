typedef int s32;
typedef float f32;

extern "C" void func_005792E8(s32 *arg0, s32 arg1);
extern "C" f32 mBlockTransition__getBlock(s32 *arg0, f32 fparg0, f32 fparg1);

struct func_003CCB60_arg0 {
    char pad0[0x96D0];
    s32 unk96D0;
};

extern "C" void func_003CCB60(void *arg0, f32 fparg0, f32 fparg1) {
    s32 sp0;
    struct func_003CCB60_arg0 *self = (struct func_003CCB60_arg0 *)arg0;

    func_005792E8(&sp0, self->unk96D0);
    mBlockTransition__getBlock(&sp0, fparg0, fparg1);
    self->unk96D0 = sp0;
}
