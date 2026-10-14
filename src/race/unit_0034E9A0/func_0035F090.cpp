/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V6 { float f[6]; };
extern int D_00620930;
extern unsigned char D_00620934;
extern unsigned char D_00620935;
extern V6 D_006208E8;
extern V6 D_00620900;
extern V6 D_00620918;
extern V6 D_00843928[2];
extern V6 D_00843958[2];
extern V6 D_00843988;
extern V6 D_008439A0;
extern V6 D_008439B8[2];
extern V6 D_008439E8[2];
extern int D_00843A18;
extern "C" float func_0035EA08(void) throw();
extern "C" int func_0035EFB8(void) throw();
extern "C" void *func_005A48D8(void *, int, unsigned);

inline float *getComponent(V6 *p) { return &p->f[2]; }

extern "C" void func_0035F090(V6 *arg0, V6 *arg1, int arg2) {
    if (D_00620930 == 0) {
        func_0035EA08();
        D_00620930 = 1;
    }
    unsigned char *pInit = &D_00620935;
    if (*pInit == 0) {
        D_008439B8[0] = D_00620918;
        D_008439B8[1] = D_00620900;
        func_005A48D8(&D_008439E8[0], 0, 0x18);
        func_005A48D8(&D_008439E8[1], 0, 0x18);
        D_00843A18 = 0;
        *pInit = 1;
    }
    for (int i = 0; i < 2; i++) {
        V6 *k = &D_00843988;
        V6 *c = &D_008439A0;
        V6 *tgt = i == 0 ? &D_006208E8 : &D_00620918;
        unsigned char st = D_00620934;
        if (st == 0) {
            if (i == 1) tgt = &D_00620900;
        } else if (st == 3) {
            k = &D_00843928[i];
            c = &D_00843958[i];
            tgt = i ? arg1 : arg0;
        }
        float *t2 = getComponent(&D_008439E8[i]);
        unsigned char st2 = D_00620934;
        if (st2 == 1) {
            if (0.0f < *t2) *t2 = 0.0f;
        } else if (st2 == 0) {
            if (*t2 < 0.0f) *t2 = 0.0f;
        }
        for (int j = 0; j < 6; j++) {
            float p = D_008439B8[i].f[j];
            float v = D_008439E8[i].f[j];
            float d = tgt->f[j] - p;
            v += (k->f[j] * d - c->f[j] * v) * 0x1.111110p-6f;
            D_008439E8[i].f[j] = v;
            p += v * 0x1.111110p-6f;
            D_008439B8[i].f[j] = p;
        }
    }
    switch (D_00620934) {
    case 0:
        break;
    case 1:
        if (func_0035EFB8()) D_00620934 = 2;
        break;
    case 2:
        if (arg2 == 1) D_00620934 = 3;
        break;
    case 3:
        if (arg2 == 2) D_00620934 = 4;
        break;
    case 4:
        if (func_0035EFB8()) D_00620934 = 0;
        break;
    }
}
