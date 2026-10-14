typedef int s32;
struct Obj { char p[0x14]; char b14; };
extern s32 D_0064A308;
extern s32 D_0064A30C;
extern s32 D_008A028C;
extern s32 D_008A04B4;
extern "C" s32 func_0050B460(s32, s32, s32, Obj *);
extern "C" s32 func_0050E138(Obj *o, s32 a, s32 b) {
    o->b14 = 0;
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C == 0) return -16;
    D_008A04B4 = a;
    D_008A028C = b;
    return func_0050B460(1, 0xDC, 0x1C, o) ? -5 : 0;
}
