/* compiler: ee-gcc2.96-no-strict-aliasing */
extern float D_008439B8[12];
extern float D_008439E8[12];
extern float D_00620918[6];

extern "C" int func_0035EFB8() {
    float e2 = 0.0f;
    float e1 = 0.0f;
    float a;
    for (int i = 0; i < 6; i++) {
        float d = 60.0f;
        if (i >= 3) d = 0x1.657182p-4f;
        a = D_008439B8[i] + D_008439B8[i + 6];
        a = (D_00620918[i] - a) / d;
        e1 += a * a;
        a = D_008439E8[i] + D_008439E8[i + 6];
        a = a / d;
        e2 += a * a;
    }
    int r = 0;
    if (e1 < 0x1.0624dcp-10f) {
        r = 1;
        if (!(e2 < 0x1.0624dcp-10f)) r = 0;
    }
    return r;
}
