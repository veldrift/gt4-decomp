/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float *func_004A5B70(int);
extern "C" void func_0049FD50(int, float *, int, int, int, int);
extern "C" void func_00218430(void *self, float *p, float f) {
    float *v = func_004A5B70(3);
    int i = 1;
    float &py0 = p[i];
    float &px1 = p[2];
    float &py1 = p[3];
    float &vy0 = v[i];
    float x0 = p[0];
    float dx = px1 - x0;
    float dy = py1 - py0;
    float len;
    __asm__("sqrt.s %0, %1" : "=f"(len) : "f"(dx * dx + dy * dy));
    float k = f * 0.5f / len;
    float ox = k * dy;
    float oy = k * dx;
    v[0] = x0 + ox;
    vy0 = py0 - oy;
    v[2] = 0;
    v[3] = p[0] - ox;
    v[4] = py0 + oy;
    v[5] = 0;
    v[6] = px1 + ox;
    v[7] = py1 - oy;
    v[8] = 0;
    v[9] = px1 - ox;
    v[10] = py1 + oy;
    v[11] = 0;
    func_0049FD50(4, v, 0, 0, 0, 0);
}
