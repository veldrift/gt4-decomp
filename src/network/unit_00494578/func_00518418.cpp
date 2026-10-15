static inline int distance(char *end,char *start) { return end-start; }
struct Packet { unsigned char id,a,b,c,d,pad; short x,y,n; };
struct Obj { unsigned char z0,z1,z2,z3,z4,z5; char pad6[10]; char *start,*end,*limit; char pad1c[16]; char sub[8]; unsigned size; char pad38[4]; char *source; };
extern "C" struct Obj *func_00515EE8(int) throw();
extern "C" int func_00538710(void *,int *);
extern "C" int func_00538418(void *,int);
extern "C" int func_00538630(void *,void **);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern "C" int func_00518418(char *out,int id,int n) {
 struct Packet pkt;
 struct Obj *p;
 int result=0;
 int flag;
 void *data;
 data=0;
 flag=0;
 if(!out) return result;
 if(n<=0) return result;
 p=func_00515EE8(id);
 if(!p) return (int)p;
 pkt.id=id;
 pkt.a=p->z5;
 pkt.b=p->z3;
 pkt.c=p->z1;
 pkt.d=p->z2;
 pkt.x=distance(p->end,p->start);
 pkt.y=distance(p->limit,p->start);
 pkt.n=n;
 func_005A4724(out,&pkt,12);
 if(func_00538710(p->sub,&flag)!=0) return 0;
 if(flag) {
  if(func_00538418(p->sub,1)!=0) return 0;
  func_005A4724(p->start,p->source,p->size);
 }
 if(func_00538630(p->sub,&data)!=0) return 0;
 func_005A4724(out+12,data,n);
 return n+12;
}
