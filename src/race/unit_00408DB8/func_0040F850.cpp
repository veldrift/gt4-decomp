/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

extern "C" void func_0040F850(int p0, int p1, f32 *p2, f32 *p3, int *p4, f32 *p5, f32 *p6, f32 *p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int p15, f32 fp0, f32 fp1, int *sp40) {
    f32 temp;
    f32 zero;

    *p5 += fp1;
    *sp40 = 0;
    temp = *p5;
    *p2 = temp;
    *p3 = temp;
    *p4 = 0;
    zero = *(f32 *)p4;
    *p7 = zero;
    *p6 = zero;
}
