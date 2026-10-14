/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float *func_00420F70(float *, float) throw();
extern "C" void func_0057D8A0(float,float *,float *);
extern "C" void func_00421258(float *a,float *s,float *c) {
    float first[4];
    float second[4];
    float spare[4];
    float tmp[4];
    float *p = second;
    float x = *a;
    first[0] = x;
    float y = *func_00420F70(tmp,x);
    p[0] = y;
    func_0057D8A0(y,s,c);
}
