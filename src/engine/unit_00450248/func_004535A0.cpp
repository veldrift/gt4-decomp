struct Vec { float x, y, z, w; };
extern Vec D_006AA8D0;
extern "C" void func_004A53F8();
extern "C" void func_004A7A54();
extern "C" void func_004A7AA8(Vec *, const Vec *);
extern "C" void func_004A5400();
extern "C" int func_004535A0(int odd, float a, float b) {
    if (b < 0.0f) return 1;
    Vec v;
    func_004A53F8();
    func_004A7A54();
    func_004A7AA8(&v, &D_006AA8D0);
    func_004A5400();
    if (odd) v.x = -v.x;
    float neg_b = -b;
    float ratio = a / b;
    float t = ratio * v.x + a;
    if (neg_b < v.x) return t * t < v.y * v.y + v.z * v.z;
    return 1;
}
