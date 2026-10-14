/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x, y, z; };
struct S {
    V3 v;
    V3 a;
    int flag;
    V3 b;
    float t;
};
struct Obj { char pad[0x5AC]; int f5ac; };
extern "C" float func_00344798(void *, float);
extern "C" float func_003447F8(void *, float);
extern "C" float func_00344828(void *, float);
extern "C" void func_00395A38(void *, void *, void *, int, float, float, float, float);
extern "C" void func_005F5040(float *, float *);
extern "C" void func_003FE680();

extern "C" int func_003FEB68(void *arg0, Obj *obj, V3 *p, float *out) {
    S s;
    float *pa = &s.a.x;
    float zero = 0.0f;
    *out = zero;
    s.t = zero;
    s.flag = 0;
    int k = obj->f5ac;
    float x = func_00344798(obj, zero);
    float y = func_003447F8(obj, zero);
    float z = func_00344828(obj, zero);
    float *pz = &s.v.z;
    s.v.x = x;
    s.v.y = y;
    *pz = z;
    func_005F5040(&p->x, pa);
    float hx = p->x;
    float lx = s.v.x;
    if (hx < lx) {
        float t = hx;
        hx = lx;
        lx = t;
    }
    zero = p->z;
    float lz = *pz;
    if (zero < lz) {
        float t = zero;
        zero = lz;
        lz = t;
    }
    float *pb = &s.b.x;
    float *pp = &p->x;
    func_00395A38(arg0, (void *)func_003FE680, &s, k, lx, lz, hx, zero);
    if (s.flag) {
        func_005F5040(pb, pp);
        *out = s.t;
        return 1;
    }
    return 0;
}
