struct Key { float v[17]; };
struct Obj { int field0; Key keys[2]; int current; };
extern "C" void func_004A7890(float, float, float);
extern "C" void func_0049AC00(float, float, float, float);
extern "C" void func_0033B2A8(Obj *o, float t) {
    float u = 1.0f - t;
    int i = o->current;
    float *p = o->keys[i].v + 9;
    o = (Obj *)((char *)o + (1-i) * 0x44);
    float size = p[1];
    float blend = o->keys[0].v[9] * t + p[0] * u;
    func_004A7890(size, 1.0f / size, 1.0f);
    func_0049AC00(blend, size, p[2], p[3]);
}
