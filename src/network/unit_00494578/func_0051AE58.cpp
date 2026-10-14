struct Sub { char p[0x1C]; int v; };
struct Obj { char p[0x100]; Sub *s; };
struct Global { char p[0x30]; int (*fn)(int *,Obj *); char p34[0xE4]; Obj *current; };
extern Global *D_0064B4B4;
extern "C" void func_005310D0(Obj *,int);
extern "C" int func_0051AE58(Obj *o,int unused,unsigned index,int *value) {
 int out=0x100;
 if(!o) return 4;
 if(index>=0x40) return 4;
 Global *g=D_0064B4B4;
 if(o!=g->current) return 4;
 Sub *s=o->s;
 if(!s) return 4;
 if(g->fn(&out,o)!=0) return 4;
 if(out!=0x100) {
  s->v=*value;
  func_005310D0(o,-1);
 }
 return 4;
}
