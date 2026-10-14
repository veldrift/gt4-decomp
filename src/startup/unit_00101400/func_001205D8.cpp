/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
extern "C" void func_004A7288(f32, f32, f32, f32, f32, f32);
extern "C" void func_001205D8(f32 *arg0, f32 *arg1, f32 fparg0, f32 fparg1) {
    f32 x, y;
    func_004A7288(*arg0, *arg1, 0.0f,
                  x = *arg0 + fparg0 * 15.0f,
                  y = *arg1 + fparg1 * 30.0f, 0.0f);
    *arg0 = x + fparg0 * 30.0f;
    *arg1 = y;
    func_004A7288(x, y, 0.0f, *arg0, y, 0.0f);
}
