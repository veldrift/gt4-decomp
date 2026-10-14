/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct In { char p[0x11]; char b11; char p12[0xA]; char b1C; char p1D[0x54]; char b71; char p72[0x72]; s16 sE4; };
struct G { char p[0x2C]; s32 *f2C; char p30[4]; In *f34; };
extern G *D_006452D4;
extern "C" void func_004BC6E8(G *);
extern "C" s32 func_004BC098(void) {
    G *g = D_006452D4;
    if (*g->f2C == 0x65) return 0x8000024C;
    func_004BC6E8(g);
    D_006452D4->f34->b11 = 0;
    D_006452D4->f34->b1C = 0;
    D_006452D4->f34->b71 = 0;
    D_006452D4->f34->sE4 = 0;
    return 0;
}
