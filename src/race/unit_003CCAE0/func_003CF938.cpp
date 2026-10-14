/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tbl { char pad[0x96D0]; float x[24][2]; float y[24][2]; };
static inline float *get(Tbl *t, int i, int offset) { return (float *)((char *)t + (i * 8 + offset)); }
extern "C" void func_003CF938(char *self, int a, int b, float dt, float fx, float fy)
{
    Tbl *t = (Tbl *)(self + 8);
    float *px = get(t, a * 4 + b, 0x96D0);
    float *py = get(t, a * 4 + b, 0x9790);
    float *pvx = get(t, a * 4 + b, 0x96D4);
    float *pvy = get(t, a * 4 + b, 0x9794);
    fx += -*px * 10.0f;
    fy += -*py * 10.0f;
    fx -= *pvx * 2.59f;
    fy -= *pvy * 2.59f;
    fx *= dt;
    fy *= dt;
    *pvx += fx;
    *pvy += fy;
    *px += *pvx * dt;
    *py += *pvy * dt;
    if (*px >= 1.0f) {
        *px = 1.0f;
        *pvx = 0.0f;
    } else if (*px <= -1.0f) {
        *px = -1.0f;
        *pvx = 0.0f;
    }
    float *y = get(t, a * 4 + b, 0x9790);
    if (*y >= 1.0f) {
        *y = 1.0f;
        t->y[a * 4 + b][1] = 0.0f;
    } else if (*y <= -1.0f) {
        *y = -1.0f;
        t->y[a * 4 + b][1] = 0.0f;
    }
}
