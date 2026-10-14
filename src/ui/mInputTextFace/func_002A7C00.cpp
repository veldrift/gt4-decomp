/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mgr {char pad[0x30];float x,y;char pad2[12];unsigned color;char pad3[32];int field68;};
struct Obj {char pad[4];char *vtbl;};
struct E0 {short delta,index;void (*fn)(void *);};
struct E1 {short delta,index;void (*fn)(void *,void *);};
struct E4 {short delta,index;void (*fn)(void *,float,float,float,float);};
extern Mgr *PDISTD__global_font_manager;
extern char D_0069BA98[];
extern "C" unsigned func_00202EA8(float *,float);
extern "C" char *func_002314E8(Obj *);
extern "C" float func_00490640(Mgr *);
extern "C" float func_00490830(Mgr *);
extern "C" void func_00490890(Mgr *,float,float);
extern "C" void func_00490950(Mgr *,const char *,...);
extern "C" void func_00490A08(Mgr *,char *,char *);
extern "C" int func_004B8988(void *);
extern "C" void func_004B89B0(void *,int,char *,int);
extern "C" void func_002A7C00(char *self,Obj *o,int current) {
 char buf[64];
 void *list=self+0x578;
 float x=PDISTD__global_font_manager->x;
 float y=PDISTD__global_font_manager->y;
 float step=func_00490830(PDISTD__global_font_manager);
 int total=func_004B8988(list);
 int limit,start;
 if(total<6){limit=total;start=0;}else{limit=6;start=current/6*6;}
 float *color=(float *)(self+0x114);
 int i=0;
 {E0 *e=(E0 *)(o->vtbl+0x1D8);e->fn((char *)o+e->delta);}
 {E1 *e=(E1 *)(o->vtbl+0x198);e->fn((char *)o+e->delta,self+0x134);}
 float w=func_00490640(PDISTD__global_font_manager)*16.0f*0.5f;
 float h=step*(limit+1);
 {E4 *e=(E4 *)(o->vtbl+0x1A0);e->fn((char *)o+e->delta,x,y-step*(limit+2),w,h);}
 PDISTD__global_font_manager->field68=0;
 func_00490890(PDISTD__global_font_manager,x,y-h);
 Mgr *m=PDISTD__global_font_manager;
 m->color=func_00202EA8(color,1.0f);
 func_00490950(PDISTD__global_font_manager,D_0069BA98,current+1,total);
 for(;i<limit;i++){
  int index=start+i;
  func_00490890(PDISTD__global_font_manager,x,y-step*(limit-i));
  if(index==current){Mgr *m=PDISTD__global_font_manager;m->color=func_00202EA8((float *)(self+0x144),1.0f);}
  else {Mgr *m=PDISTD__global_font_manager;m->color=func_00202EA8(color,1.0f);}
  if(index<total){func_004B89B0(list,index,buf,16);func_00490A08(PDISTD__global_font_manager,buf,func_002314E8(o));}
 }
 func_00490890(PDISTD__global_font_manager,x,y);
}
