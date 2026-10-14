/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0x40]; int v40; char p44[0x3edc]; int state; };
struct Request { int v0,v4,v8; char pC[12]; void *fn18; int v1C; void *fn20; int v24,v28,v2C,v30,v34,v38,v3C,v40; };
extern char D_004FFBD8[],D_004FFC60[];
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_00505618(Request *,int *);
extern "C" void func_004F8858(Obj *,int) throw();
extern "C" int func_004FFC90(Obj *o) {
 if (o->state) return 1;
 Request req;
 int out;
 func_005A48D8(&req,0,0x44);
 req.fn18=D_004FFBD8;
 req.fn20=D_004FFC60;
 req.v38=6;
 req.v3C=o->v40;
 out=0;
 req.v0=0;req.v4=0;req.v8=0;req.v28=0;
 int r=func_00505618(&req,&out);
 func_004F8858(o,r);
 if (r) return 0;
 o->state=1;
 return 1;
}
