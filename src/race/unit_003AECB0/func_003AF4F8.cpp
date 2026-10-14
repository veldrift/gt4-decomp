// Reconstructed void rendering contract follows eight concrete direct callers.
// The spelling of the original stripped return typedef is not claimed.
struct TextureState { char physicalPrefix[32];unsigned long clamp; };
struct Texture { char physicalPrefix[24];TextureState*state; };
extern "C" int func_00499728(Texture*);
extern "C" void func_0049CC48(TextureState*);
extern "C" void func_004A4550(unsigned,int);
extern "C" float func_003AFD18(float,float,unsigned);
extern "C" void func_003AF6E0(float,float,float,float,float,float,float,float);
// PLZCW is the EE packed leading-sign-count hardware operation.
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
// Drawing helpers' incidental results are not consumed by this physical view.
extern "C" void func_003AF4F8(Texture*t,float x0,float y0,float x1,float y1,int filter,int blend){
 if(t){func_00499728(t);func_0049CC48(t->state);func_004A4550(2,filter);func_004A4550(3,blend);
 unsigned long bits=t->state->clamp;unsigned width=(bits>>14&1023)+1;unsigned height=(bits>>34&1023)+1;
 float u=(float)width/(float)extentPower(width);float v=(float)height/(float)extentPower(height);
 func_003AF6E0(x0,y0,x1,y1,0,0,u,v);
 }
}
