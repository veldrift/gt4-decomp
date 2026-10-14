struct Quat {
    float x, y, z, w;
};

extern "C" void func_0057D8A0(float *s, float *c, float a);

extern "C" void func_0048C008(Quat *q, float ax, float ay, float az) {
    float sx, cx, sy, cy, sz, cz;

    float hx = ax * 0.5f;
    float hy = ay * 0.5f;
    float hz = az * 0.5f;
    func_0057D8A0(&sx, &cx, hx);
    func_0057D8A0(&sy, &cy, hy);
    func_0057D8A0(&sz, &cz, hz);
    q->x = sx * cy * cz + cx * sy * sz;
    q->y = cx * sy * cz - sx * cy * sz;
    q->z = sx * sy * cz + cx * cy * sz;
    q->w = cx * cy * cz - sx * sy * sz;
}
