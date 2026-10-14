/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_0057D118(float, float);
struct Matrix { float v[12]; };
struct Vec3 { float x,y,z; };
extern "C" void func_003E2600(Vec3 *out, Matrix *in) {
    float x = in->v[9];
    float den = 1.0f - x*x;
    __asm__("sqrt.s %0, %1" : "=f"(den) : "f"(den));
    float a = -in->v[8] / den;
    float b = in->v[10] / den;
    float c = -in->v[1] / den;
    float d = in->v[5] / den;
    out->x = func_0057D118(x, den);
    out->y = func_0057D118(a, b);
    out->z = func_0057D118(c, d);
}
