struct Item { signed char x,type;short zero;int word; };
struct Group { int x,kind;char unknown[524];int capacity;Item entries[64];int first; };
struct Obj { char unknown[32];Group groups[2];int active; };
extern "C" Item* func_004B5CC0(Obj*);
extern "C" void func_004B54E8(Obj*),func_004B47F0(unsigned short*,int),func_004B5E00(Obj*,Item*,unsigned short*,int),func_004B6A38(Obj*);
extern "C" int func_004B4150(int,int,unsigned short*,int,int),func_004B4950(unsigned short*);
extern "C" unsigned short* func_004B48D0(unsigned short*,int,int);
extern "C" Item* func_004B5A48(Obj*,int,int);
extern "C" void func_0057D9C0(const char*,...);
extern char D_006B0458[];
inline int shortValue(const Item& x){return x.zero;}
inline int byteValue(const signed char& x){return x;}
inline int length(unsigned short*p){int n=0;while(p[n])++n;return n;}
extern "C" void func_004B51A8(Obj*self,int step){signed char saved[64];unsigned short buffer[256];Group*g=&self->groups[1-self->active];if(g->kind)return;int first=g->first;int combined=func_004B5CC0(self)->type;combined+=step;step=combined;if(step<=0)return;if(first>=g->capacity-1)return;for(int i=1;i<=64;i++){if(i<first)saved[i-1]=shortValue(g->entries[i]);else saved[i-1]=0;}func_004B54E8(self);int count=func_004B4150(first-1,step,buffer,256,47);if(count<0){func_0057D9C0(D_006B0458,count&255,count&0x7f00);return;}unsigned short*names=func_004B48D0(buffer,256,1);func_004B47F0(buffer,47);func_004B47F0(names,47);unsigned short*values=buffer;for(int i=0;i<count;i++){Item*item=func_004B5A48(self,g->first+i,2);item->zero=byteValue(saved[i]);item->type=func_004B4950(names);func_004B5E00(self,item,values,0);values+=length(values)+1;names+=length(names)+1;}g->first=first;func_004B6A38(self);}
