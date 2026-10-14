/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { unsigned len,cap,ref,sel; };
struct Str { char *p; };
struct Val { int type; float n; };
struct Input { int a,b; char *p; };
extern Rep D_00659E20;
extern char D_006AE358[];
extern "C" int func_00481690(void *) throw();
extern "C" int func_0057DA20(char *,const char *,...);
extern "C" char *strobe__toUpper(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *strobe__Any__setMember(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" void *func_004812C8(void *,const Str &) throw();
extern "C" void *func_00476790(void *,void *) throw();
extern "C" void free(void *) throw();
extern "C" void func_00480FA0(Input *,int) throw();
extern "C" Val *func_004855A8(Val *out,char *owner,int flag,Input *in) {
 char buf[16];
 void *map=owner+4;
 int count=func_00481690(map);
 if(flag) {
  func_0057DA20(buf,D_006AE358,count++);
  Str key;
  Rep *r=&D_00659E20;
  char *p=(char *)(r+1);
  Str *keyptr=&key;
  char *src=buf;
  if(r->sel) p=strobe__toUpper(r);
  else r->ref++;
  keyptr->p=p;
  strobe__Any__setMember(keyptr,0,-1,src,func_0057F260(src));
  func_00476790(func_004812C8(map,*keyptr),in->p-8);
  r=(Rep *)(keyptr->p-16);
  if(--r->ref==0) free(r);
 }
 func_00480FA0(in,flag);
 out->type=6;out->n=(float)count;
 return out;
}
