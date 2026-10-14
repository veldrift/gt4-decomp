extern "C" void func_00576788(void*),func_005767C0(void*);extern "C" void func_005DD408(void*,void*);
struct It{void*p;};static inline void erase(void*p,It first,It last){func_005DD408(p,first.p);}
extern "C" void func_00250BF8(char*p,void*n){void*lock=p+232;func_00576788(lock);It a={n},b={n};erase(p+16,a,b);func_005767C0(lock);}
