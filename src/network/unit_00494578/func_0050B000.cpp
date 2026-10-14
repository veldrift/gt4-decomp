struct Config { int w[22]; void (*cb58)(); int pad5c[5]; void (*callback)(int); int tail[3]; };
typedef void (*Fn)();
typedef void (*F1)(int);
typedef void (*F3)(int,int);
typedef void (*F5)(int,int,int);
typedef void (*F7)(int,int,int,int);
typedef void (*F9)(int,int,int,int,int);
struct Params { int w0; F1 w1; int w2; F3 w3; int w4; F5 w5; int w6; F7 w7; int w8; F9 w9; int w10; int w11; int w12; int w13; Fn w14; int w15; };
struct G { int x0; char pad4[0x6c-4]; int x6c; char pad70[12]; int x7c; char pad80[0xd0-0x80]; int xd0; char padd4[0x124-0xd4]; int x124; };
extern int D_0064A308,D_0064A350,D_0064A354;
struct Callbacks { F7 x0; char pad4[0x6c-4]; F1 x6c; char pad70[12]; F5 x7c; char pad80[0xd0-0x80]; F9 xd0; char padd4[0x124-0xd4]; F3 x124; };
extern G D_008A0190;
extern Callbacks D_008A03B8;
extern "C" void func_0050A9C0(int) throw();
extern "C" void func_0050AFE0(int) throw();
extern "C" int func_0052E510(void *);
extern "C" int func_0052E568(void *,void *);
extern "C" int func_0050FE80(void);
extern "C" void func_0050AFA0(int);
extern "C" int func_0050B000(Params *p,int *out) {
 Config config; int result[8];
 if (D_0064A308==1) { *out=-1; return -18; }
 D_0064A350=p->w15;
 D_0064A354=p->w13;
 func_0050A9C0(0);
 func_0052E510(&config);
 config.w[21]=p->w0;
 if (p->w11) { func_0050AFE0(p->w11); config.tail[0]=p->w12; }
 else func_0050AFE0(0);
 config.callback=func_0050AFA0;
 config.cb58=p->w14;
 config.w[1]=p->w13;
 if (func_0052E568(&config,result)!=0) { *out=-1; return -1; }
 G *a=&D_008A0190; Callbacks *b=&D_008A03B8;
 a->x6c=p->w2;
 b->x6c=p->w1;
 a->x124=p->w4;
 b->x124=p->w3;
 a->x7c=p->w6;
 b->x7c=p->w5;
 a->x0=p->w8;
 b->x0=p->w7;
 b->xd0=p->w9;
 a->xd0=p->w10;
 int r=func_0050FE80();
 if (r!=0) { *out=-1; return -1; }
 D_0064A308=1;
 *out=0;
 return r;
}
