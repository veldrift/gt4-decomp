/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x20]; float kx,ky,x,y; int w,h; };
struct Font { char pad[0x1c]; float x,y; char pad2[8]; int value; char pad3[0x68-0x30]; int flag; };
extern Font *PDISTD__global_font_manager;
extern "C" char *func_0044D898(char *, const char *) throw();
extern "C" void func_0044D988(Obj *) throw();
extern "C" void func_0044DBC0(Obj *,const char *,float,float);
extern "C" void func_00490290(Font *,char *);
extern "C" unsigned int func_0057F260(const char *) throw();
extern "C" int func_005A2F88(const char *) throw();
extern "C" int func_0044D9B8(Obj *self, const char *str) {
 char buf[16];
 float x,y;
 if (str==0) {
  func_0044DBC0(self,str,self->x,self->y);
  return 0;
 }
 {
  int v=0;
  self->kx=1.0f; self->ky=1.0f;
  char *s=(char *)__builtin_alloca(func_0057F260(str)+1);
  const char *p=func_0044D898(s,str);
  char c;
  while((c=*p++)!=0) {
   switch(c) {
    case '#':
     v=*p++-'0';
     if(v<0) v=0;
     break;
    case '*': {
     p=func_0044D898(buf,p);
     int a=func_005A2F88(buf);
     int b;
     if(*p==',') { p=func_0044D898(buf,p+1); b=func_005A2F88(buf); } else b=a;
     self->kx=self->kx*((float)a*0x1.47ae14p-7f);
     self->ky=self->ky*((float)b*0x1.47ae14p-7f);
     break;
    }
   }
  }
  func_0044D988(self);
  func_00490290(PDISTD__global_font_manager,s);
  PDISTD__global_font_manager->value=v;
  const char *h=(const char *)self->h;
  Font *f=PDISTD__global_font_manager;
  f->x=(float)self->w;
  f->y=(float)(int)h;
  PDISTD__global_font_manager->flag=0;
  func_0044DBC0(self,h,self->x,self->y);
 }
 return 0;
}
