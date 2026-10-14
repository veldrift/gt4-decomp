/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
struct S { char pad[5]; s8 v; };
extern float D_00843920;
extern "C" void func_00355E40(char *o, float f) {
    S *s = (S *)(o + 0x788);
    int v = s->v + (int)(f * D_00843920);
    if (v > 100) v = 100;
    else if (v < -100) v = -100;
    s->v = v;
}
