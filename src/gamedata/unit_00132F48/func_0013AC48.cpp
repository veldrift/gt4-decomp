typedef struct Face {char pad[0x2A0];int action;} Face;
extern "C" const char *D_00618890[];
extern "C" int func_0057F238(const char *,const char *);
extern "C" void func_0013AC48(Face *self,const char *name) {int i=0;const char **p=D_00618890;do{if(!func_0057F238(name,*p++)){self->action=i;break;}i++;}while(i<2);}