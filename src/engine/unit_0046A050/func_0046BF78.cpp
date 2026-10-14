/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int a,n,c,d; };
struct E { char pad[0x14]; float t; };
extern "C" int func_0046A050(void *, int);
extern "C" void func_00469F08(O *, void *, int);
extern "C" float func_0046A0B0(void *);
extern "C" E *func_00469FC8(O *, int);
extern "C" int func_0046BF78(void *p, int i, float t) {
 int r = func_0046A050(p,4);
 if (!r) return r;
 O o;
 func_00469F08(&o,p,4);
 int n=o.n;
 if(n<6) return 0;
 float len=func_0046A0B0(p);
 if(t < len*0.5f) t+=len;
 if (func_00469FC8(&o,i+1)->t < t && t < func_00469FC8(&o,n-i-3)->t) return 1;
 return 0;
}
