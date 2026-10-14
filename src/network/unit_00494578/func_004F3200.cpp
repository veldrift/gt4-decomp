/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { int a[49]; };
struct Obj { char pad[0x5a8]; char *p; };
extern Obj D_00645570;
extern char D_006C04A8[];
extern "C" int func_004F0C38(Obj *,const char *) throw();
extern "C" int func_004F0B08(Obj *,const char *) throw();
extern "C" void func_004F87E8(Obj *,int);
struct Guard { Obj *obj; Blob *src; Guard(Obj *o,Blob *s):obj(o),src(s){} ~Guard(){func_004F0B08(obj,(char *)src);} };
extern "C" void func_004F3200(Blob *src,Obj *obj) {
 if (!obj) obj=&D_00645570;
 Guard guard(obj,src);
 if (func_004F0C38(obj,D_006C04A8)!=0) return;
  int kind=src->a[6];
  int flag=0;
  if (kind<0 || kind==1) {
   func_004F87E8(obj,kind);
   flag=1;
  }
  if (flag) return;
  *(Blob *)(obj->p+0x1d8)=*src;
  func_004F87E8(obj,src->a[6]);
}
