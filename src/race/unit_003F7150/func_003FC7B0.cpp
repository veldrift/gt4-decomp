/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_003DDBC8(int, float);
extern "C" void func_003FC7B0(float *a, int *b, float t)
{
    float *p1 = a + 1;
    float *p2 = a + 2;
    *a = 1.0f;
    *p1 = 1.0f;
    *p2 = 1.0f;
    if (b[0] != 0) *a = func_003DDBC8(b[0], t);
    if (b[1] != 0) *p1 = func_003DDBC8(b[1], t);
    if (b[2] != 0) *p2 = func_003DDBC8(b[2], t);
}
