typedef unsigned int u32;
struct Record { unsigned char state,kind,flag,channel,zero,forever; char pad[2]; int value,owner; char *buffer; u32 end,start; int pos,length; short a,b; int more; char sub[4]; };
struct Pool { char pad[0x10]; int first; u32 count; };
struct Obj { char pad[0x104]; int id; };
struct Global { char pad[0x100]; u32 count; char rest[0x14]; Obj *obj; };
extern Global D_00854038;
extern "C" Record *func_00515EE8(int) throw();
extern "C" Pool *func_0051B8A8(Obj *,u32);
extern "C" char *func_005316F8(unsigned);
extern "C" void func_00531738(char **);
extern "C" int func_00537FC8(void *,int,void *);
extern "C" int func_00516F10(int *out,int n,int length,u32 channel,int flag,int value,int kind,int a,int b) {
 if(!out) return 23;
 *out=-1;
 if(n<0) return 23;
 if(length<0) return 23;
 Global *g=&D_00854038;
 Obj *obj=g->obj;
 if(!obj) return 15;
 if(channel>=g->count) return 23;
 if(obj->id==256) return 21;
 Pool *pool=func_0051B8A8(obj,obj->id);
 if(!pool) return 21;
 if(pool->count==0) return 20;
 for(u32 i=0;i<pool->count;) {
  int index=i+pool->first;
  i++;
  Record *r=func_00515EE8(index);
  if(!r) return 20;
  if(r->state==2) continue;
  r->buffer=func_005316F8(n);
  if(!r->buffer) { r->state=0; return 22; }
  if(func_00537FC8(r->sub,n,r->buffer)) { func_00531738(&r->buffer); return 20; }
  r->state=2;
  u32 buffer=(u32)r->buffer;
  r->a=a;
  r->owner=obj->id;
  r->length=length;
  r->channel=channel;
  r->flag=flag;
  r->b=b;
  r->end=buffer+n;
  r->start=buffer;
  r->kind=kind;
  r->value=value;
  r->zero=0;
  r->more=0;
  r->pos=0;
  if(value==-1) r->forever=1; else r->forever=0;
  *out=index;
  return 0;
 }
 return 20;
}
