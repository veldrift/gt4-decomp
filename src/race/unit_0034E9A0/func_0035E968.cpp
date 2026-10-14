/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Config { char pad[0xe4]; unsigned char a,b,c,d,e,f; };
struct Settings { float a,b,c,d,e,f; };
extern Config D_00622110;
extern Settings D_006208B8;
extern "C" void func_0035E968() {
    D_006208B8.a = D_00622110.a * 10.0f;
    D_006208B8.b = D_00622110.b * 10.0f;
    D_006208B8.c = D_00622110.c * 10.0f;
    D_006208B8.d = D_00622110.d * 0x1.1df468p-6f;
    D_006208B8.e = D_00622110.e * 0x1.1df468p-6f;
    D_006208B8.f = D_00622110.f * 0x1.1df468p-6f;
}
