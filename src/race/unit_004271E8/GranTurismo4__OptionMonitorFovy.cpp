struct P { float f0; float a4; float a8; float aC; float a10; };
struct G { char pad[0x38CD4]; P p; };
extern G *D_00622F4C;
extern "C" float func_0057D118(float, float);
extern "C" float GranTurismo4__OptionMonitorFovy() {
    P *p = &D_00622F4C->p;
    float b = p->a4;
    float y = p->a8 * b;
    float x = p->a10 * 0.5f;
    return func_0057D118(x, y);
}
