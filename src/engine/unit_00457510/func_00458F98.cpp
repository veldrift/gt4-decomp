/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline void fix(unsigned &p,int offset,unsigned limit) {
 unsigned v=p;
 if (v>=limit) p=v+offset;
}
struct Obj { unsigned head[2]; unsigned arr[4]; unsigned pad18;
 unsigned p1c,p20,p24,p28,p2c,p30,p34,p38,p3c,p40,p44,p48,p4c,p50,p54;
};
extern "C" void func_00458F98(Obj *o,int offset,unsigned limit) {
 for(int i=0;i<4;i++) if(o->arr[i]) fix(o->arr[i],offset,limit);
 if(o->p1c) fix(o->p1c,offset,limit);if(o->p24) fix(o->p24,offset,limit);if(o->p2c) fix(o->p2c,offset,limit);
 if(o->p34) fix(o->p34,offset,limit);if(o->p3c) fix(o->p3c,offset,limit);if(o->p44) fix(o->p44,offset,limit);
 if(o->p4c) fix(o->p4c,offset,limit);if(o->p50) fix(o->p50,offset,limit);if(o->p54) fix(o->p54,offset,limit);
}
