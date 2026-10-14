/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x858]; int sel; };
struct Bank { char pad[8]; const unsigned short *base; };
struct Rec { char pad[4]; short start,end; };
extern "C" int func_004B4B40(void *,int) throw();
extern "C" Rec *func_004B5CC0(void *) throw();
extern "C" void func_004B5E00(void *,void *,unsigned short *,int) throw();
extern "C" int func_004B6230(void *,unsigned short *,const unsigned short *,int,int,int,int) throw();
extern "C" void func_004B6578(void *,int,int,int);
extern "C" void func_004B63D0(Obj *self,int a,int b) {
 unsigned short buf[8];
 Bank *bank=(Bank *)((char *)self+(1-self->sel)*0x41c+0x20);
 if(func_004B4B40(self,1)<0x100) {
  const unsigned short *base=bank->base;
  Rec *rec=func_004B5CC0(self);
  int n=func_004B6230(self,buf,base,rec->end,rec->end-rec->start,a,b);
  func_004B5E00(self,rec,buf,n);
  int len=0;
  if(*buf) {
   unsigned short *p=buf;
   do { p++;len++; } while(*p);
  }
  func_004B6578(self,a,n,len);
 }
}
