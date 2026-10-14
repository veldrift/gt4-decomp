struct Global { int a,b,c,d,e,f,flag; };
struct Packet { int pad[6]; int a,b,c,d,f,e; };
extern Global D_008A0398;
extern int D_008A04D8, D_008A02B0;
extern char D_0064A318[];
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_0050D3D0(void *, int, void *) throw();
extern "C" void func_0050E6E8(void *, int, int) throw();
extern "C" void func_0050E828(void) {
    Packet p;
    if (D_008A0398.e != 0) {
        func_005A48D8(&p, 0, 0x30);
        func_0050D3D0(D_0064A318, 0x8d, &p);
        p.e = D_008A0398.e;
        p.a = D_008A0398.a;
        p.b = D_008A0398.b;
        p.c = D_008A0398.c;
        p.d = D_008A0398.d;
        p.f = D_008A0398.f;
        D_008A0398.flag = 1;
        func_0050E6E8(&p, D_008A04D8, D_008A02B0);
    }
}
