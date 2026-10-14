struct Req { int a; unsigned char b; char pad[3]; int c,d; unsigned char e; char pad2; short f; int g,h; };
extern "C" void (*D_0064B4D8)(Req *);
extern int D_0064B4DC;
extern "C" void func_00536CA0(int a, unsigned char b, int c, int d, int e, int f, int g) {
 Req r;
 if (D_0064B4D8) {
 r.a=a; r.b=b; r.c=c; r.d=d; r.e=e; r.f=f; r.g=g; r.h=D_0064B4DC;
 D_0064B4D8(&r);
 }
}
