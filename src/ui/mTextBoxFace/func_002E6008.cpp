/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad1[0x124];
    int i124; int i128;
    char pad2[0x32C - 0x12C];
    signed char tab[0x80];
    int i3AC; int i3B0; float f3B4; int i3B8; float f3BC; int i3C0; int i3C4;
};
extern void *PDISTD__global_font_manager;
extern "C" int func_002E5D88(O *, int) throw();
extern "C" int func_002E57D8(O *, int *, int, int) throw();
extern "C" float func_00490830(void *);
extern "C" void func_004908C0(void *, float, float);
extern "C" void func_002E6008(O *o, float f)
{
    int sp0;
    float f2 = o->f3BC;
    if (f2 > 0.0f) {
        o->f3BC = f2 + ((float)o->i3C0 - f2) * 0x1.999998p-3f;
    }
    float f22 = func_00490830(PDISTD__global_font_manager);
    float f21 = (f - f22 * (float)o->i3AC) + (o->f3BC * f22 + f22);
    sp0 = o->i124;
    while (sp0 != o->i128) {
        float f20 = f22 * (float)o->tab[sp0];
        if (f21 <= -f20) {
            f21 += f20;
        } else {
            if (f <= f21) break;
            float t = f21;
            func_004908C0(PDISTD__global_font_manager, 0.0f, t);
            int v = func_002E5D88(o, sp0);
            o->f3BC = o->f3BC + (float)v;
            if (o->i3C4 != 0) {
                o->i3C0 = o->i3C0 + v;
            }
            f21 += f20;
        }
        func_002E57D8(o, &sp0, 0x80, 1);
    }
}
