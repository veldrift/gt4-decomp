/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {int a,b,size,c;char *p10,*p14,*p18,*p1c,*p20,*p24,*p28,*arr[2],*p34,*p38;};
extern "C" {
void func_00454410(void *);
int func_00454580(void *);
void func_00458238(void *) throw();
void func_00458F98(void *,int,unsigned);
void func_00498B28(void *);
void *func_005A47D4(void *,const void *,unsigned) throw();
}
static inline char *relocate(char **addr,int delta,unsigned limit) {
 unsigned v=*(unsigned *)addr;
 if(v>=limit) *(unsigned *)addr=v+delta;
 return *addr;
}
extern "C" char *func_00458400(Obj *p,unsigned limit,int delta) {
 if(limit) {
  char *old=(char *)(limit-delta);
  func_005A47D4((void *)limit,old,(char *)p+p->size-old);
  p->size+=delta;
 }
 if(p->p10) func_00458F98(relocate(&p->p10,delta,limit),delta,limit);
 if(p->p14) relocate(&p->p14,delta,limit);
 if(p->p18) func_00454410(relocate(&p->p18,delta,limit));
 if(p->p1c) func_00458238(relocate(&p->p1c,delta,limit));
 if(p->p20) {if(func_00454580(relocate(&p->p20,delta,limit))) func_00454410(p->p20);}
 if(p->p24) func_00458238(relocate(&p->p24,delta,limit));
 if(p->p28) {if(func_00454580(relocate(&p->p28,delta,limit))) func_00454410(p->p28);}
 for(int i=0;i<2;i++) {
  if(p->arr[i]) {
   relocate(&p->arr[i],delta,limit);
   if(func_00454580(p->arr[i])) func_00454410(p->arr[i]);
  }
 }
 if(p->p34) func_00454410(relocate(&p->p34,delta,limit));
 if(p->p38) func_00498B28(relocate(&p->p38,delta,limit));
 return (char *)p+p->size;
}
