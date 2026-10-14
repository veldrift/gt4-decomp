/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_0057D118(float, float);
extern "C" float func_0059D2A0(float);
extern "C" void func_004880E8(void *, float, float, float);
struct Angle {
    float x;
    Angle(float a) : x(a) {}
    Angle(const Angle &a) : x(a.x) {}
};
struct Input { float v[16]; };
struct Output { float x,y,z,w; char q[16]; };
static inline void setq(void *q, const Angle &x, const Angle &y, const Angle &z) {
    func_004880E8(q, x.x, y.x, z.x);
}
extern "C" void func_00418A88(Output *o, Input *m) {
    float x = func_0057D118(m->v[6], m->v[10]);
    float y = func_0059D2A0(-m->v[2]);
    float z = func_0057D118(m->v[1], m->v[0]);
    setq(o->q, Angle(x), Angle(y), Angle(z));
    o->x = m->v[12];
    o->y = m->v[13];
    o->z = m->v[14];
}
