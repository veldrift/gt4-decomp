typedef float f32;

extern "C" void func_004A3040(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" void func_004A3230(int arg0);

extern "C" void func_00472E30(void) {
    f32 zero = 0.0f;
    func_004A3040(zero, zero, zero, zero);
    func_004A3230(3);
}
