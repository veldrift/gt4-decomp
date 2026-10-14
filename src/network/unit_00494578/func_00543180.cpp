struct Obj { char pad[0x1c]; void *a,*b; };
extern "C" Obj* func_00538988(int) throw();
extern "C" int func_00538830(int*) throw();
extern "C" int func_00538B08(void**,int) throw();
extern "C" void* func_005A4724(void*,const void*,unsigned);
extern "C" void* func_005A48D8(void*,int,unsigned);
extern "C" int func_00543180(int id,char* data) {
 Obj* p=func_00538988(id);
 if(!p)return -1;
 char* second;
 if(func_00538830((int*)data) || (second=data+0x40,func_00538830((int*)second))){
  if(p->a)func_005A48D8(p->a,0,0x40);
  if(p->b)func_005A48D8(p->b,0,0x40);
 } else {
  if(!p->a)func_00538B08(&p->a,0x40);
  if(!p->b)func_00538B08(&p->b,0x40);
  func_005A4724(p->a,data,0x40);
  func_005A4724(p->b,second,0x40);
 }
 return 0;
}
