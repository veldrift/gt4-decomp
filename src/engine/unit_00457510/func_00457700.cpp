struct A{float a,b,c;};static inline void init(A*s,float zero,float one){s->a=zero;s->b=zero;s->c=one;}void func_00457700(A*s){for(unsigned n=0;n<5;++n){init(s,0.0f,1.0f);++s;}}
