typedef unsigned char u8;
struct Input;
extern float func_00385768(Input*);
extern float func_00385728(Input*);
extern float func_00385718(Input*);
extern float func_003856D8(Input*);
extern float func_00385A78(Input*);
extern float func_00385A28(Input*);
#define F(p,n) (*(float*)((u8*)(p)+(n)))
#define I(p,n) (*(int*)((u8*)(p)+(n)))
inline float maxf(float x,float y){float r;asm("max.s %0,%1,%2":"=f"(r):"f"(x),"f"(y));return r;}
inline float minf(float x,float y){float r;asm("min.s %0,%1,%2":"=f"(r):"f"(x),"f"(y));return r;}
extern "C" void func_003B1DB0(int mode,void*out,Input*input){
 F(out,4)=func_00385768(input);I(out,0)=1;
 if(mode==3){float v=func_00385728(input);F(out,12)=0;F(out,16)=v;}
 else if(mode==4){F(out,16)=0;F(out,12)=func_00385728(input);}
 else if(mode==5){F(out,16)=0;F(out,12)=func_00385728(input);}
 else{F(out,16)=func_00385718(input)*3.14f*.0625f;F(out,12)=func_00385728(input)*3.14f*.0625f;}
 if(mode==1){
  F(out,88)=func_003856D8(input);F(out,92)=func_003856D8(input);
  float angle=F(out,4);
  if(angle<0)F(out,88)*=1-minf(maxf(-angle/1.5707963f,0),1)*.5f;
  else F(out,92)*=1-minf(maxf(angle/1.5707963f,0),1)*.5f;
  I(out,84)=1;
 }else if(mode==3){F(out,88)=func_00385A78(input);F(out,92)=func_00385A28(input);I(out,84)=1;}
 else I(out,84)=0;
}
