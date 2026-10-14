typedef float f32;

extern "C" f32 func_0057D1F0(f32 x);

extern "C" f32 func_0035A008(f32 fparg0, f32 fparg1) {
    f32 temp_f21;
    f32 temp_f0;

    temp_f21 = func_0057D1F0(fparg0);
    temp_f0 = func_0057D1F0(fparg1);
    return temp_f21 * (3.0f - (temp_f0 + temp_f0));
}
