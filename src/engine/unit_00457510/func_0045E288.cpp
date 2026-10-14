/* compiler: ee-gcc2.96-no-strict-aliasing */
union I { int i; float f; };
struct V2 { float x, y; };
struct E { float v[2]; char pad[0x24]; };
struct M { float a, b, c, d; };
struct Obj {
    float k0, k1;
    char pad0[0x220];
    E ents[10];
    char pad1[0x41C - 0x228 - 10 * 0x2C];
    I idx;
    float f420, f424;
    char pad2[0x20];
    float f448;
    char pad3[4];
    int f450;
};
extern "C" float func_0045C0C8(void) throw() __attribute__((const));
extern "C" void func_00350530(int, int, I, float);
static inline float sum(float a, float b) { return a+b; }
extern "C" void func_0045E288(Obj *o, V2 *out, M *m, V2 *in)
{
    V2 n;
    V2 a;
    V2 b;
    float e11 = func_0045C0C8();
    n.y = o->f420;
    n.x = -o->f424;
    V2 *pa = &a;
    V2 *pb = &b;
    pa->x = m->a * n.x + m->c * n.y;
    a.y = m->b * n.x + m->d * n.y;
    E *e = &o->ents[o->idx.i];
    float cross = e->v[0] * a.y - e->v[1] * pa->x;
    pb->x = sum(m->a * e->v[1], m->b * -e->v[0]);
    b.y = sum(m->c * e->v[1], m->d * -e->v[0]);
    float den = o->k0 + (pb->x * n.x + b.y * n.y) * (-cross * o->k1);
    float s = den != 0.0f ? (-(e11 + 1.0f) * (in->x * n.x + in->y * n.y)) / den : 0.0f;
    out->x = s * n.x;
    out->y = s * n.y;
    float v = s;
    if (v < 0.0f) v = -v;
    o->f448 = o->f448 + v / 100000.0f;
    func_00350530(o->f450, 0, o->idx, v);
}
