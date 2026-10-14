typedef unsigned int u32;
struct Self;struct Context;struct Car;struct Object;
extern "C" void*func_005C15B0(unsigned int);
extern "C" void func_005C1628(void*);
extern "C" int func_0035E3F0(Object*);
extern "C" void func_003EE7C0(Self*,Context*);
static inline Car*car(Context*c,int i){return (*(Car***)(*(char**)((char*)c+0x60)+8))[i];}
static inline Object*object(Car*c){return *(Object**)((char*)c+0x18);}
extern "C" void func_003EE808(Self*self,Context*ctx){
 int i=0;
 int*ranks=(int*)func_005C15B0(24);
 int*used=(int*)func_005C15B0(24);
 u32*keys=(u32*)func_005C15B0(24);
 for(i=0;i<6;++i){used[i]=0;ranks[i]=0;keys[i]=0;}
 for(i=0;i<6;++i)keys[i]=(u32)func_0035E3F0(object(car(ctx,i)));
 for(i=0;i<6;++i){
 for(int j=i+1;j<6;++j){
 if(keys[i]!=keys[j]){
 if(keys[i]>keys[j])++ranks[i];else ++ranks[j];
 }
 }
 }
 for(i=0;i<6;++i){
 int rank=ranks[i];
 while(used[rank]==1)++rank;
 *(int*)((char*)self+0x2fc+i*0x188)=rank;
 used[rank]=1;
 }
 func_005C1628(ranks);func_005C1628(used);func_005C1628(keys);
 func_003EE7C0(self,ctx);
}
