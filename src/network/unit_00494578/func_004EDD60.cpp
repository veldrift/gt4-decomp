/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x48]; void *a48,*a4c; char *data; int a54,n58,n5c; };
extern char D_006C0260[],D_006C0268[];
extern "C" int func_004EDA88(Obj*,int,int,const char*) throw();
extern "C" int func_004EDB50(Obj*,int,int,const char*,const char*) throw();
extern "C" int func_004EE330(Obj*,int);
extern "C" int func_004EE368(Obj*,int);
extern "C" int func_004EE3A0(Obj*,int);
extern "C" char *func_004EE5F8(Obj*,void*,int,const char*);
extern "C" char *func_004EE698(Obj*,int);
extern "C" char *func_004EE7A0(Obj*,int);
extern "C" void func_0057DA20(char*,const char*,...);
extern "C" int func_0057F238(const char*,const char*) throw();
extern "C" int func_0057F260(const char*) throw();
extern "C" int func_005A2F88(const char*) throw();
extern "C" void *func_005A48D8(void*,int,unsigned);
extern "C" void func_005A6900(char*,const char*,unsigned);
extern "C" void func_005A6AB0(char*,const char*,unsigned) throw();
extern "C" void func_004EDD60(Obj *o,int id,const char *name,const char *a,const char *b) {
 char buf[256]; struct { int f[10]; } flags; char result[16];
 func_005A6AB0(o->data+0xe00,a,256);
 func_005A6AB0(o->data+0xf00,b,256);
 int n1 = 255, n2 = 255;
 func_005A6AB0(buf,a,255);
 n1 -= func_0057F260(buf); func_005A6900(buf,D_006C0260,n1);
 n2 -= func_0057F260(buf); func_005A6900(buf,b,n2);
 int n=func_004EE3A0(o,id),i;
 if(n<0) return;
 i=0;
 for(;i<n;i++) if(func_0057F238(buf,func_004EE7A0(o,i))==0) break;
 if(i==n) {
  if(func_004EDA88(o,2,id,buf)<0) return;
  if(func_004EE3A0(o,id)<0) return;
 } else { if(func_004EDB50(o,2,id,buf,buf)<0) return; }
 if(func_004EDA88(o,1,id,name)<0) return;
 if(func_004EE368(o,id)<0) return;
 const char *x=func_004EE5F8(o,o->a48,o->n58,name);
 const char *y=func_004EE5F8(o,o->a4c,o->n5c,buf);
 func_005A6AB0(o->data,x,256);
 func_005A6AB0(o->data+256,y,256);
 n=func_004EE330(o,id);
 if(n<0) return;
 func_005A48D8(&flags,0,40);
 for(i=0;i<n;i++) {
  char *p=func_004EE698(o,i);
  for(;;) {
   int c=*p; if(!c) break;
   if(((unsigned char*)0x006D0E79)[c]&4) { int ix=func_005A2F88(p)-1; int *entry=flags.f+ix; *entry=1; break; }
   p++;
  }
 }
 for(i=0;i<10 && flags.f[i];i++) ;
 func_0057DA20(result,D_006C0268,i+1);
 func_004EDA88(o,0,id,result);
}
