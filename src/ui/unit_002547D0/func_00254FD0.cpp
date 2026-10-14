extern char D_00699920[];
extern "C" void* func_00326750(int,int,void*);
struct R {float x,y,w,h;R():x(0),y(0),w(1),h(1){}};
struct S {R a,b;unsigned flag0:1,flag1:1,rest:30;S(){flag0=0;flag1=0;}};
inline void* operator new(unsigned int,void* p){return p;}
extern "C" S* func_00254FD0() {S* p=(S*)func_00326750(36,4,D_00699920);return p?new(p) S:0;}
