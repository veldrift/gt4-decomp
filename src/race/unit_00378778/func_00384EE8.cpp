/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub14 {
    char pad[0x104];
};
struct Sub11C {
    char pad[4];
};
struct Obj {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    Sub14 s14;
    float f118;
    Sub11C s11C;
};

extern "C" float func_0036EAD8(float) throw();
extern "C" float func_0036EB98(float, float) throw();
extern "C" void func_00384C48(Sub11C *, int, float, float) throw();
extern "C" float func_00384D70(Sub11C *) throw();
extern "C" void func_00384DB8(Sub14 *, float) throw();
extern "C" float func_00384E38(Sub14 *) throw();

extern "C" void func_00384EE8(Obj *o, int arg1, int arg2, float a, float b) {
    o->f118 = b;
    func_00384DB8(&o->s14, a);
    func_00384C48(&o->s11C, arg1, 1.0f, b);
    float t = func_00384E38(&o->s14);
    float u = func_0036EB98(a, o->f0) + (t - a);
    float k = 1.0f;
    if (arg2 != 0) k = func_00384D70(&o->s11C) * 0.9f + 0x1.333332p-1f;
    if (b <= 0.0f) b = 0.0f;
    if (b >= 1.0f) b = 1.0f;
    float f4 = o->f4;
    f4 = f4 + ((o->f8 * k * u * b + o->fC * f4) / 60.0f) * o->f10;
    o->f4 = f4;
    o->f0 = func_0036EAD8(o->f0 + f4 / 60.0f);
}
