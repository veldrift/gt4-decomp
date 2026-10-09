typedef struct Obj {int f0;int f4;int f8;int fC;int f10;} Obj;
extern void func_005C1628(Obj *);
void func_00154B78(Obj *self,int flags) {self->f8=0;self->f4=0;self->f10=0;if(flags&1)func_005C1628(self);}
