/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Source {char data[0x1c0];int state;char name[24];};
struct Saved {int v[0xac/4];};
struct Obj {char pad[0x5a8];char *target;char pad2[0x498];Saved saved;};
extern Obj D_00645570;
extern char D_006C0D98[];
extern "C" {
int func_004F0C38(Obj *,const char *);
int func_004F0B08(Obj *,const char *);
void func_004F87E8(Obj *,int) throw();
}
struct Guard {Obj *obj; const char *name; Guard(Obj *o,const char *n):obj(o),name(n){} ~Guard(){func_004F0B08(obj,name);} };
extern "C" void func_004FE9E8(Source *src,Obj *obj) {
 if(!obj)obj=&D_00645570;
 Guard g(obj,src->name);
 if(func_004F0C38(obj,D_006C0D98))return;
 int done=0;
 if(src->state<0 || src->state==1) {func_004F87E8(obj,src->state);done=1;}
 if(done)return;
 *(Source *)(obj->target+0x1d8)=*src;
 func_004F87E8(obj,src->state);
 obj->saved=*(Saved *)src;
}
