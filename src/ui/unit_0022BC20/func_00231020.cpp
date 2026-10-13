typedef int s32;
typedef float f32;

extern "C" void func_00230EC0(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_00230ED8(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_00231020(void *arg0, f32 fparg0, f32 fparg1) {
    f32 sp0;
    f32 sp4;
    f32 temp_f0;
    f32 temp_f1;

    func_00230EC0(arg0, &sp0, &sp4);
    temp_f0 = sp0 + fparg0;
    temp_f1 = sp4 + fparg1;
    sp0 = temp_f0;
    sp4 = temp_f1;
    func_00230ED8(arg0, temp_f0, temp_f1);
}
