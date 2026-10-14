struct Q { float x, y, z, w; };
extern "C" void func_0057D8A0(float, float *, float *);

extern "C" void func_0048BB88(Q *q, float a, float b, float c) {
    float s0, c0, s1, c1, s2, c2;
    float ha = a * 0.5f;
    float hb = b * 0.5f;
    float hc = c * 0.5f;
    func_0057D8A0(ha, &s0, &c0);
    func_0057D8A0(hb, &s1, &c1);
    func_0057D8A0(hc, &s2, &c2);
    float t6 = s0 * c1;
    float t2 = c0 * c1;
    float t0 = c0 * s1;
    float t1 = s0 * s1;
    q->x = t6 * c2 - t0 * s2;
    q->y = t0 * c2 + t6 * s2;
    q->z = t1 * c2 + t2 * s2;
    q->w = t2 * c2 - t1 * s2;
}
