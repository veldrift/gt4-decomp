struct W { char p0[0x488]; float m488; char p1[0x494 - 0x48C]; float m494; char p2[0x4E8 - 0x498]; float m4E8, m4EC; char p3[0x4FA - 0x4F0]; short m4FA; char p4[0x520 - 0x4FC]; unsigned char m520; char p5; unsigned char m522; };
struct S { char p[0x104]; W w; };
extern float D_008438C4;
extern signed char D_0062046B, D_0062046C, D_0062046D;
extern "C" float func_00356168(S *);
extern "C" float func_003561D0(S *s)
{
    W *w = &s->w;
    float c = D_008438C4;
    float t = (w->m4E8 + w->m4EC) * (float)w->m4FA * 0x1.b7860ep-14f;
    t = t / (t + c + c);
    float a = w->m494;
    if (w->m522 == 2) a = w->m488;
    if (a <= t) return -1.0f;
    a = (2.0f * (a - t)) / (1.0f - t);
    a = a * func_00356168(s);
    int n = w->m520;
    if (D_0062046D >= n) {
        a = 0.0f;
    } else if (a > 1.0f) {
        if (n < D_0062046B || D_0062046C < n) a = 1.0f;
    }
    return a + -1.0f;
}
