/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
struct Tbl { u8 *data; char p4[6]; u16 a,b; };
struct Head { char pad[0x50]; Tbl table; };
struct Obj { char pad[0x24]; Head *h; };
struct Sub { u16 idx; u8 count,zero3,zero4,zero5; u16 flags; };
struct Out { int tag; Sub v; short value; u8 zero, pad; };
extern "C" int func_004BF2D0(Obj *,int,u16 *,int,u16 *,int *) throw();
extern "C" short func_004C07F8(Head *,int,u16,int) throw();
extern "C" void func_004C2030(Obj *,Out *) throw();
extern "C" short func_004C37B0(Obj *,unsigned int);
extern "C" int func_004C3918(Obj *,int,short);
extern "C" Out *func_004C8C20(Obj *,int);
extern "C" int func_004C8ED0(u16 *);
extern "C" int func_004C9580(unsigned int *,int);
extern "C" int func_004C2348(Obj *self,u16 *name,unsigned int *filter,Out **ret) {
 u16 index;
 int count;
 count=0;
 index=0;
 Head *head=self->h;
 int len=func_004C8ED0(name);
 int result;
 if(len>=64) { count=0; result=0; }
 else result=func_004BF2D0(self,0x300,name,func_004C8ED0(name),&index,&count);
 if(result<0) return result;
 if(count==0) { *ret=0; return 0; }
 Out *alloc=func_004C8C20(self,count*16);
 *ret=alloc;
 if(!alloc) return 0x80000333;
 result=count;
 Out *out=alloc;
 int i=0;
 if(i<count) {
 Tbl *t=&head->table;
 do {
 short id=func_004C07F8(head,0x300,index,0);
 int off=id*20;
 int n=(t->a+t->b)*6;
 u8 *p=(u8*)(n+(int)(t->data+off));
 u8 *q=(u8*)(off+(int)(t->data+n));
 if(q[0x13]==0 && func_004C9580(filter,(q[0x10]<<8)|p[0x11])==1) {
 Sub *v=&out->v;
 out->zero=0;
 v->idx=id;
 u8 *r=(u8*)(off+(int)(t->data+(t->a+t->b)*6));
 v->count=r[0xc]+r[9];
 u8 *base=t->data;
 int n=(t->a+t->b)*6;
 u8 *p=(u8*)(n+(int)(base+off));
 u8 *q=(u8*)(off+(int)(base+n));
 int mask=p[0xf]&0x1f;
 int hi=q[0x10]<<8;
 int lo=p[0x11];
 v->zero3=0;
 v->flags=lo|hi|(mask<<11);
 out->tag=id|0x800000;
 v->zero4=0;
 v->zero5=0;
 out->value=func_004C37B0(self,func_004C3918(self,0x300,id));
 out++;
 } else result--;
 i++;
 index++;
 } while(i<count);
 }
 if(result<=0) {
 func_004C2030(self,*ret);
 result=0;
 *ret=0;
 }
 return result;
}
