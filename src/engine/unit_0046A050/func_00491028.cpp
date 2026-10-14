struct Font;
struct Self {char opaque0[0x14];Font* font;char opaque18[0xc];float scale;char opaque28[8];float x,y;char opaque38[4];float extent;char opaque40[0x14];float left;char opaque58[4];float right;char opaque60[4];unsigned flags;char opaque68[0x10];int state;};
struct Argument {int value;int opaque4;};
typedef int (*Draw)(int,char*,Self*);
extern "C" int func_00490C48(const char*);
extern "C" void* func_005A6AB0(void*,const void*,unsigned);
extern "C" int func_00492ED0(int,char*,Self*);
extern "C" int func_00492EA8(int,char*,Self*);
extern "C" int func_00493C70(Self*,Draw,char*,const char*,const Argument*);
extern "C" int func_004940E8(Self*,Draw,int,const char*);
extern "C" int func_00491AC0(Font*);
extern "C" void func_00491028(Self* self,const char* text,const Argument* limit,int count,int mode,int measureOnly,float step){
 if(count<=0)return;
 int remaining=count;
 do{
  int n=func_00490C48(text);
  char* line=(char*)__builtin_alloca(n+1);
  func_005A6AB0(line,text,n+1);text+=n+1;line[n]=0;
  self->x=0;int saved=self->state;
  if(mode)func_00493C70(self,func_00492ED0,0,line,limit);
  else func_004940E8(self,func_00492ED0,1,line);
  float width=self->x-(func_00491AC0(self->font)/2)*self->scale;
  if(self->extent<width)self->extent=width;
  self->state=saved;
  unsigned align=self->flags&3;float span=self->right-self->left;
  if(align==1)self->x=(span-width)*0.5f;else if(align==2)self->x=span-width;
  if(!measureOnly){
   if(mode)func_00493C70(self,func_00492EA8,0,line,limit);
   else func_004940E8(self,func_00492EA8,0,line);
  }
  self->y+=step;
 }while(--remaining);
}
