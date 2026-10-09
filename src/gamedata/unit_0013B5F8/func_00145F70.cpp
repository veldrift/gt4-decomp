extern "C" const char *D_006188B0[];
extern "C" int func_0057F238(const char *,const char *);
extern "C" int func_00145F70(const char *name) {const char **p=D_006188B0;for(int i=0;*p;i++,p++){if(!func_0057F238(*p,name))return i;}return -1;}