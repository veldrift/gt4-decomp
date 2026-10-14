struct Context { char pad[0x74]; int state; char sub[4]; };
extern int D_0064B480;
extern Context *D_0064B47C;
extern "C" int func_00535780(int);
extern "C" int func_00539818(void *, int);
extern "C" int func_00539990(void *, int *);
extern "C" int func_00536ED0(int,int,int,int,int,int);
extern "C" int func_00530250(int a,int b,int c,int d,int e,int f) {
 int state=D_0064B480;
 if(state!=1) return 0x11;
 if(D_0064B47C->state!=state) return 0x2b;
 int r=func_00535780(func_00539818(D_0064B47C->sub,0));
 if(r) return r;
 int s=func_00536ED0(a,b,c,d,e,f);
 r=func_00535780(func_00539990(D_0064B47C->sub,0));
 return r ? r : s;
}
