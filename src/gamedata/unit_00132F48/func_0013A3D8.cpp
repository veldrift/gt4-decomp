typedef struct Handle {void *p;char pad[12];} Handle;
extern "C" void func_0021B790(void *,void *);
extern "C" void func_002106E0(void *,void *);
extern "C" void func_00210710(void *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00265F48(void *,int);
extern "C" void func_0013A3D8(void *self,void *name) {Handle temporary;Handle empty;Handle *target=(Handle *)((char *)self+0xCC);func_0021B790((char *)self+0xA0,name);empty.p=0;func_002106E0(&temporary,&empty);if(target!=&temporary){void *p=temporary.p;if(p)func_003285A8(p);if(target->p)func_003285F8(target->p);target->p=p;}func_00210710(&temporary,2);func_00265F48(self,0);}