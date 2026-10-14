/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00422150(void *, float *, float *);
extern "C" float *func_00421168(float *, float *);
extern "C" double func_0057FB50(float);
extern "C" void func_0057D9C0(const char *, ...);
extern char D_006A4818[];
extern "C" void func_00418DE8(float *o) {
    float pos[4], rot[4], tmp[4];
    func_00422150(o+4,pos,rot);
    double a = func_0057FB50(o[0]);
    double b = func_0057FB50(o[1]);
    double c = func_0057FB50(o[2]);
    double d = func_0057FB50(pos[0]);
    double e = func_0057FB50(pos[1]);
    double f = func_0057FB50(pos[2]);
    float *p = tmp;
    func_00421168(p,rot);
    double g = func_0057FB50(*p);
    func_0057D9C0(D_006A4818,a,b,c,d,e,f,g);
}
