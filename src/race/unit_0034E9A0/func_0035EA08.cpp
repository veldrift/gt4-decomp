/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Col { char p[0xDC]; unsigned char r, g, b, a; };
extern Col D_00622110;
extern float D_00843988[6];
extern float D_008439A0[6];
extern "C" float func_0035E968() throw();

extern "C" float func_0035EA08() {
    for (int i = 0; i < 3; i++) {
        D_00843988[i] = D_00622110.r;
        D_00843988[i + 3] = D_00622110.g;
        D_008439A0[i] = D_00622110.b;
        D_008439A0[i + 3] = D_00622110.a;
    }
    return func_0035E968();
}
