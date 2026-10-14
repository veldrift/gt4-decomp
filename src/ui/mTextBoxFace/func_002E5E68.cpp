/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Body {
    char pad1[0x118];
    int i124; int i128;
    char pad2[0x32C - 0x12C];
    signed char tab[0x80];
    int i3AC; int i3B0; float f3B4;
};
struct O { char pad[12]; Body body; };
extern void *PDISTD__global_font_manager;
extern "C" int func_002E5D88(O *, int) throw();
extern "C" void func_002E57D8(O *, int *, int, int) throw();
extern "C" float func_00490830(void *);
extern "C" void func_004908C0(void *, float, float);
static inline int dec(int v) { int r = v - 1; if (r < 0) r = v + 0x7F; return r; }
extern "C" void func_002E5E68(O *o)
{
    int sp0;
    int lim = o->body.i3AC;
    int a2 = o->body.i3B0;
    if (a2 >= lim) {
        sp0 = o->body.i124;
        if (sp0 != o->body.i128) {
            do {
                func_002E5D88(o, sp0);
                func_002E57D8(o, &sp0, 0x80, 1);
            } while (sp0 != o->body.i128);
        }
    } else {
        int s3 = 0, s4 = 0;
        int v = o->body.i128;
        sp0 = v - 1;
        if (sp0 < 0) sp0 = v + 0x7F;
        int s0 = dec(o->body.i124);
        for (; sp0 != s0; func_002E57D8(o, &sp0, 128, -1)) {
            s3 += o->body.tab[sp0];
            if (s3 >= o->body.i3B0) { s4 = sp0; break; }
        }
        if (s3 > 0) {
            int t = o->body.i3B0 - s3;
            func_004908C0(PDISTD__global_font_manager, 0.0f, func_00490830(PDISTD__global_font_manager) * (float)t + o->body.f3B4);
            sp0 = s4;
            for (int k=0; k<s3; k++) {
                func_002E5D88(o, sp0);
                func_002E57D8(o, &sp0, 0x80, 1);
            }
        }
    }
}
