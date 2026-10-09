typedef struct Garage {char pad[0x174];int weight;} Garage;
extern "C" char D_0068F520[],D_0068F528[];
extern "C" void *D_00624984;
extern "C" void func_00490A40(void *,char *,const char *,int,const char *);
extern "C" void func_001463E0(Garage *self,const char *units,char *text) {int weight=self->weight;if(weight<=0)__builtin_memcpy(text,D_0068F520,5);else func_00490A40(D_00624984,text,units,weight,D_0068F528);}