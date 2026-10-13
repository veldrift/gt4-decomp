typedef float f32;

extern "C" void func_00421640(f32 *out, const f32 *in) {
    int off = 12;
    f32 y = in[1];
    const f32 *w = (const f32 *)((const char *)in + off);
    f32 *dw = (f32 *)((char *)out + off);
    f32 k = 3.0f;
    f32 y3 = y * k;
    f32 x0 = in[0];
    f32 x3 = x0 * k;
    f32 z3 = in[2] * k;
    f32 r0 = ((y3 - x0) - z3) + w[0];
    f32 r2 = (x3 - (y3 + y3)) + z3;
    f32 r1 = y3 - x3;
    dw[0] = r0;
    out[2] = r2;
    out[1] = r1;
    out[0] = in[0];
}
