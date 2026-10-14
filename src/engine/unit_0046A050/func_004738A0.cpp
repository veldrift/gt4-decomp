struct G { char pad4C_[0x4C]; int f4C; char pad50[0x14]; int f64; };
extern G *PDISTD__global_font_manager;

extern "C" void func_004738A0(int a, int b) {
    int r = 0;
    switch (b) {
    case 1: r = 2; break;
    case 2: r = 1; break;
    case 3: r = 0; break;
    default: r = 0; break;
    }
    G *g = PDISTD__global_font_manager;
    g->f64 = r;
    g->f4C = 1;
}
