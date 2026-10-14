struct Entry { int a,b,c,d,e; char pad[0x44-20]; };
struct Obj { int handle; char pad[0x80]; Entry *entries; char pad88[0x14]; unsigned short count; short pad9e; int state; char tail[4]; };
extern "C" unsigned int func_00525FE0();
extern "C" int func_00525868(Obj *,Entry *,unsigned int);
extern "C" int func_00529650(int,int);
extern "C" void func_0053A860(void *,int);
extern "C" int func_00525C58(Obj *p,int id) {
 unsigned int idx=func_00525FE0();
 int off=idx*0x44;
 if(idx<p->count) {
  Entry *e=(Entry *)((char *)p->entries+off);
  func_0053A860(p->tail,id);
  int b=e->b;
  p->state=0;
  if(id==b) e->d=1;
  else if(id==e->c) e->e=1;
  return func_00525868(p,e,idx);
 }
 return func_00529650(p->handle,id);
}
