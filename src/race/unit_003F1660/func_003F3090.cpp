/* compiler: ee-gcc2.96-nogcse */
struct Aux { char p[0x1068]; float f1068; float f106c[2]; };
struct Inner {
    char p0[0x24]; float f24, f28, f2c;
    char p1[0x53C - 0x30]; float f53c; char p2[4]; float f544, f548, f54c;
    char p3[0x59C - 0x550]; float f59c, f5a0, f5a4, f5a8[2];
    char p4[0x5C3 - 0x5B0]; char c5c3;
};
struct Obj { char p[0x10]; Aux *aux; char q[0x104 - 0x14]; Inner s; };
extern float D_0062230C, D_00622310, D_00622314, D_00622318;
extern "C" void func_003F2DB8(char *, float) throw();
extern "C" float func_0057D118(float, float);

extern "C" void func_003F3090(Obj *o)
{
    Inner *s = &o->s;
    float k = s->f59c;
    float w = s->f53c;
    Aux *aux = o->aux;
    float vel = *(float *)((char *)o + 0x54C);
    float f20 = w * w;
    if (k != 0.0f) {
        float v = s->f5a0 + k * D_00622314 * vel;
        s->f5a0 = v;
        if (v > 1.0f)
            s->f5a0 = 1.0f;
    } else {
        float v = s->f5a0 - D_00622318 * vel;
        s->f5a0 = v;
        if (v < 0.0f)
            s->f5a0 = 0.0f;
    }
    float ang = func_0057D118(s->f544 * s->f24 + s->f548 * s->f28 + s->f54c * s->f2c, s->f53c);
    float f2 = D_0062230C;
    float delta = 1.0f - f2;
    float t6 = 1.0f - s->f5a0;
    f2 += delta * t6;
    if (s->c5c3 == 2)
        f2 = 20.0f;
    f2 *= f20;
    float r = aux->f1068 * f2;
    if (s->f53c >= 0.0f)
        r = -r;
    s->f5a4 = r;
    float f12 = D_00622310 + (1.0f - D_00622310) * t6;
    if (ang < 0.0f)
        ang = -ang;
    if (ang > 0x1.657182p-3f)
        f12 = 0.0f;
    else if (ang > 0x1.657182p-4f)
        f12 *= (0x1.657182p-3f - ang) / 0x1.657182p-4f;
    f12 *= f20;
    for (int i = 0; i < 2; i++)
        s->f5a8[i] = aux->f106c[i] * f12;
    func_003F2DB8((char *)o, f12);
}
