extern "C" float D_006208B8[];
inline float*entry(float*a,int i){return (float*)((int)a+i*4);}
extern "C" void func_0035EE50(float*a,float*b){for(int i=0;i<6;++i,++b){float limit=D_006208B8[i];float value=*entry(a,i);float lower=-limit;if(value<lower){*entry(a,i)=lower;*b=0.0f;}else if(limit<value){*entry(a,i)=limit;*b=0.0f;}}}
