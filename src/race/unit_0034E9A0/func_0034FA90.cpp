/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cfg { char p[0x1064]; float m1064; };
struct W { char p[0x53C]; float m53C; char p1[0x59C - 0x540]; float m59C; };
struct Car { char p[0x10]; Cfg *cfg; char p1[0x104 - 0x14]; W w; };
extern float D_00843630[6];
extern "C" int Automobile__getDrawMode(Car *);
extern "C" float func_0034FA90(Car *car, short *out)
{
    if (Automobile__getDrawMode(car) != 3) return 0.0f;
    W *w = &car->w;
    float *D = D_00843630;
    float v = w->m53C;
    float x = w->m59C;
    float p = D[0] * car->cfg->m1064 * v * v;
    p *= 1.0f - x;
    float a = v;
    if (a < 0.0f) a = -a;
    float r;
    if (a < D[1]) {
        r = D[3];
    } else if (D[2] < a) {
        r = D[4];
    } else {
        r = D[3] + ((a - D[1]) * (D[4] - D[3])) / (D[2] - D[1]);
    }
    *out = (short)(unsigned)r;
    if (D[5] < p) p = D[5];
    return p;
}
