extern int D_006208B0;
extern char D_006208E8[];
extern char D_00620900[];
extern char D_008439B8[];
extern int D_00843A18;
extern "C" void func_0035F090(void *a, void *b, int c);
extern "C" void func_0035EE50(float *a, float *b);
extern "C" int func_0035EDD8(float *v);

extern "C" void func_0035F700(void) {
    float tmp[6];
    if (D_006208B0 != 0) {
        func_0035F090(D_006208E8, D_00620900, 0);
        char *s = (char *)D_008439B8;
        func_0035EE50((float *)s, (float *)s);
        func_0035EE50((float *)(s + 0x18), (float *)(s + 0x18));
        for (int i = 0; i < 6; i++) tmp[i] = *(float *)(s + i * 4) + *(float *)(s + i * 4 + 0x18);
        D_00843A18 = func_0035EDD8(tmp);
    }
}
