/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00476768(void *,void *);
extern "C" void func_004768C0(void *);
struct Val { int kind; float value; char pad[8];
 Val() {kind=1;}
 Val(float v) {kind=6; value=v;}
 Val(const Val &v) {func_00476768(this,(void *)&v);}
 ~Val() {func_004768C0(this);}
};
struct Stable { char pad[0x6c]; struct Cell {char pad[0xb0]; int stable; char tail[0xc];} cells[6]; };
struct Args { int a,b; char *end; };
struct Entry {short delta,index; int (*fn)(void *);};
struct Entry2 {short delta,index; Val (*fn)(void *,void *,int,Args *);};
struct Obj {char pad[12]; char *vt; char rest[0x4e0]; int rank,visible; char *parent; int enabled;};
extern char D_006A36F0[],D_006A3700[],D_006A3710[],D_006A3720[],D_006A3730[],D_006A3740[],D_006A3750[],D_006A3760[],D_006A3770[];
extern "C" {
void func_003B76F0(void *,int,int,int);
void func_00476AE8(void *,void *); void func_00476B30(void *,int);
char *strobe__Any__toString(void *); float func_00477460(void *);
void func_00480FA0(void *,int); void func_004857C8(char *);
unsigned func_0057F260(const char *) throw();
int func_005FBDD0(void *,const char *,unsigned,unsigned);
}
extern "C" Val ResultArcade__callFunction(Obj *self,void *name,int n,Args *args) {
 if(func_005FBDD0(name,D_006A36F0,0,func_0057F260(D_006A36F0))==0) {
  int i=(int)func_00477460(args->end-8); func_00480FA0(args,n);
  Val t; int *p=(int *)(i*0xc0+(unsigned)self+0x11c);
  func_00476B30(&t,*p); *p=0; return t;
 } else if(func_005FBDD0(name,D_006A3700,0,func_0057F260(D_006A3700))==0) {
  func_00480FA0(args,n); return Val((float)self->rank);
 } else if(func_005FBDD0(name,D_006A3710,0,func_0057F260(D_006A3710))==0) {
  int i=(int)func_00477460(args->end-8); func_00480FA0(args,n);
  Val t; func_00476AE8(&t,(char *)self+i*0xc0+0x6c); return t;
 } else if(func_005FBDD0(name,D_006A3720,0,func_0057F260(D_006A3720))==0) {
  int i=(int)func_00477460(args->end-8); func_00480FA0(args,n);
  Val t; func_00476AE8(&t,(char *)self+i*0xc0+0x9c); return t;
 } else if(func_005FBDD0(name,D_006A3730,0,func_0057F260(D_006A3730))==0) {
  int i=(int)func_00477460(args->end-8); func_00480FA0(args,n);
  Val t; func_00476B30(&t,i<self->visible); return t;
 } else if(func_005FBDD0(name,D_006A3740,0,func_0057F260(D_006A3740))==0) {
  func_00480FA0(args,n); Val t; func_00476B30(&t,self->enabled); return t;
 } else if(func_005FBDD0(name,D_006A3750,0,func_0057F260(D_006A3750))==0) {
  func_003B76F0(self->parent+0xf4,1,0,0);
 } else if(func_005FBDD0(name,D_006A3760,0,func_0057F260(D_006A3760))==0) {
  func_004857C8(strobe__Any__toString(args->end-8));
 } else if(func_005FBDD0(name,D_006A3770,0,func_0057F260(D_006A3770))==0) {
  func_00480FA0(args,n); Val t; Entry *e=(Entry *)(self->vt+0x80);
  func_00476B30(&t,e->fn((char *)self+e->delta)); return t;
 } else {
  Entry2 *e=(Entry2 *)(self->vt+0x88); return e->fn((char *)self+e->delta,name,n,args);
 }
 func_00480FA0(args,n); return Val();
}
