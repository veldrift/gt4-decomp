/* compiler: ee-gcc2.96-no-strict-aliasing */
struct G { char pad[0x39DF8]; int v0,v1; }; extern G *D_00622F4C;
struct Self { char pad[0x64]; int idx,seed; };
extern char D_006614F8[], D_00661A70[], D_00660CD8[];
extern "C" void func_001D16E0(void *,int);
extern "C" void *func_001CBFE0(void *);
extern "C" void func_001CC060(void *,int);
extern "C" int func_001D1228(void *,int);
extern "C" int func_001D1038(void *,void *,int,int);
extern "C" int func_001D1340(void *,int,void *);
extern "C" void free(void *) throw();
extern "C" int *func_00575E60(int,int);
extern "C" void func_00579420(void *,int);
extern "C" int *func_005E7668(int *,int,int *);
extern "C" void func_00601288(int *,int *,int);
extern "C" void func_006012C0(int *,int *,void *);
struct Context { char *vt; char pad[12]; char table[0xC80]; int count; char tail[12]; ~Context(){vt=D_00660CD8;} };
struct Reader { char pad[0x4c]; char *vt; void *p; char tail[12]; };
struct Rng {char data[0x9d0];};
struct Vec { int pad; int *b,*e,*c; char tail[16]; };
extern "C" int func_004349A8(Self *self,void *out) {
 Context ctx;
 char *basevt=D_006614F8;

 func_001D16E0(&ctx,D_00622F4C->v0);
 char *table=ctx.table;
 ctx.count=0;
 Reader reader;
 Reader *r=&reader;
 func_001CBFE0(r);
 r->vt=D_00661A70; r->p=0;
 func_001D1228(r,0);
 r->p=table;
 int err=func_001D1038(r,&ctx,0,0);
 int count=ctx.count;
 if(err) { reader.vt=basevt;func_001CC060(r,0);return 0; }
 if(!count) {reader.vt=basevt;func_001CC060(r,0);return 0;}
 if(self->idx>=ctx.count) self->idx=0;
 int i=self->idx++;
 if(D_00622F4C->v1==1) {
  Rng rng;
  func_00579420(&rng,self->seed);
  int n=ctx.count;
  Vec vec; Vec *v=&vec;
  v->b=0;v->e=0;v->c=0;
  int *p; int bytes;
  if(n) {bytes=n*4;p=func_00575E60(16,bytes);}else{p=0;bytes=0;}
  v->b=p;v->e=p;v->c=(int*)((char*)p+bytes);
  union Tmp {int *p;Rng *rng;} tmp;
 int *volatile oldslot;
 int z;
  tmp.p=p;
  z=0;
  v->e=func_005E7668(p,n,&z);
  func_00601288(vec.b,vec.e,0);
  Tmp *pt=&tmp;pt->rng=&rng;
  func_006012C0(vec.b,vec.e,pt);
  int *entry=vec.b+i;
  i=*entry;
  int *old=vec.b;oldslot=old;
  if(old) free(old);
 }
 int ok=func_001D1340(table,i,out);
 int result=ctx.count;
 reader.vt=D_006614F8;
 if(!ok) result=0;
 func_001CC060(r,0);
 return result;
}
