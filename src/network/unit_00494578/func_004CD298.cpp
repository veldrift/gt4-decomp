/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Name { char data[12]; };
extern Name D_006BA2D0, D_006BA2E0;
struct Buf { int a,b; char *data; };
struct VE { short delta, idx; int (*fn)(void *,int,int); };
struct Obj { char p0[4]; void *list; char p8[0x48]; u32 size; char p54[0x14]; u32 count; char p6c[12]; VE *vt; };
struct Temp { char bytes[16]; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" int func_004CBFC0(Obj *,char *,Temp *) throw();
extern "C" int func_004CBCF0(Obj *,int,Temp *,Buf **,char **) throw();
extern "C" void func_004CA938(void *,Buf *) throw();
extern "C" int func_004CB558(Temp *) throw();
extern "C" void func_004CB040(void *) throw();
extern "C" int func_004CB8E8(Obj *,int) throw();
extern "C" Buf *func_004CA820(void *,u32) throw();
extern "C" void *func_005A48D8(void *,int,u32);
extern "C" void func_004CB490(char *) throw();
extern "C" void func_004CB1A8(char *,int) throw();
extern "C" void func_004CAA48(void *,Buf *) throw();
extern "C" int func_004CBE08(Obj *,int,Buf **,char **) throw();
extern "C" void func_004CB1F0(char *,Temp *) throw();
struct Guard { void * const p; Guard(void *v):p(v) {func_00576788(p);} ~Guard() {func_005767C0(p);} };
extern "C" int func_004CD298(Obj *o,char *name) {
 Buf *buf; char *data; Temp tmp; Guard g((char *)o+0x1c);
 Temp *t=&tmp;
 int parent=func_004CBFC0(o,name,t);
 if(parent<0) { return parent; }
 int r=func_004CBCF0(o,parent,t,&buf,&data);
 if(r>=0) { func_004CA938(o->list,buf); return -17; }
 if(r==-2) {
  VE *v; u32 i; int first;
  int err=func_004CB558(t);
  if(err<0) return err;
  v=o->vt+7;
  r=v->fn((char *)o+v->delta,0,1);
  if(r<0) return r;
  {
   i=0;
   func_004CB040(o->list);
   first=func_004CB8E8(o,r);
   for(;i<o->count;i++) {
    buf=func_004CA820(o->list,first+i);
    if(!buf) { return -5; }
    func_005A48D8(buf->data,0,o->size);
    if(i==0) {
     data=buf->data;
     *(Name *)data=D_006BA2D0;
     data[11]=16;
     func_004CB490(data); func_004CB1A8(data,r);
     data+=32;
     *(Name *)data=D_006BA2E0;
     data[11]=16;
     func_004CB490(data); func_004CB1A8(data,parent);
    }
    func_004CAA48(o->list,buf);
   }
   err=func_004CBE08(o,parent,&buf,&data);
   if(err<0) return err;
   func_005A48D8(data,0,32);
   func_004CB1F0(data,t);
   data[11]=16;
   func_004CB490(data); func_004CB1A8(data,r);
   func_004CAA48(o->list,buf);
   return 0;
  }
 }
 return r;
}
