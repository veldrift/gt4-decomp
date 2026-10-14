struct Self;
extern float D_0062030C,D_00620314;
extern unsigned char D_0062030A;
#define F(p,o) (*(float*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned int*)((char*)(p)+(o)))
extern "C" float func_0036D548(Self*self,float x,float y,float z){
 char*p=(char*)self+0x104;
 char*spec=*(char**)((char*)self+0x10);
 float steer=F(p,0x58c);
 if(steer<0)steer=-steer;
 float weight;
 if(steer<=D_0062030C)weight=1;else if(steer>=1)weight=D_00620314;
 else weight=1-(1-D_00620314)*(steer-D_0062030C)/(1-D_0062030C);
 float low=F(p,0x52c);
 float base=F(p,0x530)-low;
 if(base<0)base=-base;
 base*=F(spec,0x238);
 if(!B(p,0x520))x=-x;
 if(D_0062030A && x<0)return -97999.9921875f;
 float enabled=F(spec,0x23c);
 if(enabled!=0){
 if((U(p,0x520)&0x00ff00ff)==0x10000)return 97999.9921875f;
 int mode=B(p,0x522);
 if(!mode)return 97999.9921875f;
 if(weight==1){
 if(mode==2)return 97999.9921875f;
 if(F(p,0x48c)>.75f)return 97999.9921875f;
 y=(x+y)+z;
 if(x>0 && y>0)return 97999.9921875f;
 if(x<0 && y<0)return 97999.9921875f;
 }
 }
 base*=weight;
 if(base>=1){base=97999.9921875f;if(enabled==0)base=1;}
 return base;
}
