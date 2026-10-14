/* compiler: ee-gcc2.96-nogcse */
struct Font {char pad[0x44]; unsigned color;char p[0x20];int shadow;};
struct Face {char p0[0xA0]; float style[25]; float c104[4],c114[4],c124[4],c134[4],c144[4],c154[4];char p164[0x414];char iter[0x864];int ddc,de0,de4,de8,tick;};
struct Item {char *text; union {int type;float f;} u;};
extern "C" unsigned PDISTD__global_font_manager;
extern "C" unsigned func_00202EA8(float *,float);
extern "C" float func_002313E0(void *);
extern "C" float func_00231400(void *);
extern "C" float func_00231420(void *);
extern "C" float func_00231440(void *);
extern "C" char *func_002314E8(void *);
extern "C" void func_00231C10(void *);
extern "C" void func_00231C48(void *);
extern "C" void func_002472B8(void *,void *);
extern "C" void func_00247428(void *);
extern "C" void mWidget__virtual_70(void *,void *,int);
extern "C" unsigned long long func_00266088(void *);
extern "C" int func_002A6590(void *) throw();
extern "C" void func_002A7C00(void *,void *,int) throw();
extern "C" void func_002A7FE0(void *,void *) throw();
extern "C" void func_002A8170(void *,void *,unsigned) throw();
extern "C" void func_00490700(void *,int,int,int,int);
extern "C" void func_00490A08(void *,char *,char *);
extern "C" void func_004B84E8(void *);
extern "C" int func_004B84F8(void *);
extern "C" short func_004B8520(void *);
extern "C" int func_004B86B8(void *,Item *);
extern "C" void func_004B8B08(void *);
extern "C" void mInputTextFace__virtual_70(Face *self,void *ctx,int active) {
 mWidget__virtual_70(self,ctx,0);
 if(active) {
  Item item;
  func_00231C10(ctx);
  void *iter=self->iter; func_004B84E8(iter);
  float *style=self->style; func_002472B8(style,ctx);
  func_002A7FE0(self,ctx);
  int count=0; int focus=func_004B84F8(iter); int current;
  while(current=func_004B8520(iter), (item.u.type=func_004B86B8(iter,&item))) {
   unsigned color=func_00202EA8(style,1.0f);
   switch(item.u.type) {
    case 0:color=func_00202EA8(self->c154,1.0f);break;
    case 1:color=func_00202EA8(self->c104,1.0f);break;
    case 2:color=func_00202EA8(self->c114,1.0f);break;
    case 3:color=func_00202EA8(self->c124,1.0f);func_002A7C00(self,ctx,current);break;
    case 4:case 5:color=func_00202EA8(self->c124,1.0f);break;
    case 6:color=func_00202EA8(style,1.0f);break;
   }
   bool visible=item.u.type!=6;
   if(visible) {
    ((Font *)PDISTD__global_font_manager)->color=color;
    if(func_002A6590(self)) {
     *(unsigned *)(PDISTD__global_font_manager+0x68)=1;
     Font *font=(Font *)PDISTD__global_font_manager;
     float x=func_002313E0(ctx),y=func_00231400(ctx),w=func_00231420(ctx),h=func_00231440(ctx);
     func_00490700(font,(int)x,(int)y,(int)w,(int)h);
     char *p=func_002314E8(ctx); func_00490A08((Font *)PDISTD__global_font_manager,item.text,p);
    } else {
     *(unsigned *)(PDISTD__global_font_manager+0x68)=0;
     char *p=func_002314E8(ctx);func_00490A08((Font *)PDISTD__global_font_manager,item.text,p);
    }
   }
   if(func_00266088(self) && focus==count && (float)self->tick<15.0f) func_002A8170(self,ctx,color);
   count++;
  }
  self->tick++; if((float)self->tick>=30.0f)self->tick=0;
  func_00247428(style);func_004B8B08(iter);func_00231C48(ctx);
 }
}
