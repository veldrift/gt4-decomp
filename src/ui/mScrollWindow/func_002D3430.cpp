struct Component;
struct View {char unknown[0xbc];Component*inner;Component*outer;};
struct Rect {float x,y,width,height;Rect():x(0.0f),y(0.0f),width(0.0f),height(0.0f){} Rect(float a,float b,float c,float d){x=a;width=c;height=d;y=b;}};
extern "C" Component*func_0025C2A0(Component*);
extern "C" void func_0025B500(Component*,float*,float*,float*,float*);
extern "C" void func_0025BAA0(Component*,float*,float*,float*,float*);
extern "C" void func_0025BA38(Component*,float*,float*);
extern "C" void mWidget__getWindowSize(Component*,float*,float*);
static inline float clamp(float x,float low){return x<low?low:(0.0f<x?0.0f:x);}
extern "C" void func_002D3430(View*self,Component*child,float*outx,float*outy){
 if(!child)return;
 Rect r;float w,h;
 if(func_0025C2A0(child)==self->outer)func_0025B500(child,&r.x,&r.y,&r.width,&r.height);
 else {func_0025BAA0(child,&r.x,&r.y,&r.width,&r.height);func_0025BA38(self->outer,&w,&h);r.x-=w;r.y-=h;}
 mWidget__getWindowSize(self->outer,&h,&w);
 Rect box(0.0f,0.0f,0.0f,0.0f);mWidget__getWindowSize(self->inner,&box.width,&box.height);
 if(h>box.width){float x=(box.width-r.width)*0.5f-r.x;float min=box.width-h;*outx=clamp(x,min);}else *outx=box.x;
 if(w>box.height){float y=(box.height-r.height)*0.5f-r.y;float min=box.height-w;*outy=clamp(y,min);}else *outy=box.y;
}
