/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { float v[2]; char pad[0x10]; float *p; char pad2[0x10]; };
struct V2 { float x, y; };
struct M2 { float a, b, c, d; };
struct Obj {
    float dt, dt2;
    char pad0[0x230];
    E ents[5];
    char pad1[0x390 - 0x238 - 5 * 0x2C];
    float f390, f394, f398, f39C;
    char pad2[0x24];
    float f3C4, f3C8, f3CC, f3D0;
    char pad3[0x58];
    int idx;
};
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" void func_0045E768(Obj *, V2 *, V2 *, V2 *, V2 *);
extern "C" void func_0045E898(Obj *, V2 *, V2 *, V2 *);
static inline void set(V2 *p, float x, float y) { p->x=x; p->y=y; }
static inline void rot(V2 *out, const M2 *m, const float *v)
{
    out->x = m->a * v[0] + m->b * v[1];
    out->y = m->c * v[0] + m->d * v[1];
}
extern "C" void func_0045E570(Obj *o)
{
    V2 vel;
    M2 m;
    V2 t;
    V2 r;
    V2 d;
    float res[4];
    m.a = func_0057D1F0(o->f39C);
    m.c = func_0057D2B8(o->f39C);
    m.b = -m.c;
    m.d = m.a;
    Obj *base = (Obj *)((char *)o + o->idx * 0x2c);
    float *p = base->ents[0].p;
    E *e = &base->ents[0];
    V2 *pd = &d;
    set(pd, p[0] - o->f390, -p[2] - o->f394);
    rot(&t, &m, e->v);
    r.x = o->f3C4 - o->f3D0 * d.y;
    r.y = o->f3C8 + o->f3D0 * d.x;
    func_0045E768(o, &vel, &r, &t, pd);
    func_0045E898(o, &vel, &r, (V2 *)res);
    float w = (pd->x * vel.y - d.y * vel.x) * o->dt2;
    vel.x += res[0];
    vel.y += res[1];
    o->f3D0 += w;
    o->f3C4 += vel.x * o->dt;
    o->f3C8 += vel.y * o->dt;
    float a = o->f3CC;
    bool neg = a < 0.0f;
    float n = a + res[2] * o->dt;
    o->f3CC = n;
    if ((neg && n > 0.0f) || (!neg && n < 0.0f)) o->f3CC = 0.0f;
}
