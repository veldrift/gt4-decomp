/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float *func_00420F70(float *, float) throw();
extern "C" float func_0057D2B8(float) throw();
extern "C" float func_00421180(float *a) {
    float first[4];
    float second[4];
    float spare[4];
    float tmp[4];
    float *p = second;
    float x = *a;
    first[0] = x;
    float y = *func_00420F70(tmp, x);
    p[0] = y;
    return func_0057D2B8(y);
}
