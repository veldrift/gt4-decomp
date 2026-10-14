struct State { char pad0[8]; char name[256]; char other[256]; unsigned offset; int failed; };
extern char D_006C4B90[],D_006C49C0[],D_006C49C8[],D_006C4B98[],D_006C4BA0[];
extern const char *D_0064C168;
extern "C" int func_0053F280(char *,unsigned *,const char *) throw();
extern "C" int func_00594470(const char *,const char *,unsigned);
extern "C" void func_005A6AB0(void *,const void *,int) throw();
extern "C" int func_0053FE40(const char *name,const char **attrs,State *s) {
    if(s->failed==0) {
        if(func_0053F280(s->other,&s->offset,name)==0) s->failed=1;
        if(func_00594470(D_006C4B90,name,256)==0) {
            int i=0;
            if(*attrs) {
            do {
                switch((unsigned)i) {
                case 0:
                    if(func_00594470(D_006C49C0,attrs[0],256)!=0) s->failed=1;
                    break;
                case 1:
                    if(func_00594470(D_0064C168,attrs[1],256)!=0) s->failed=i;
                    break;
                }
                i++;
            } while(attrs[i]);
            }
        } else {
            if(func_00594470(D_006C49C8,name,256)==0 || func_00594470(D_006C4B98,name,256)==0) {
                func_005A6AB0(s->name,name,256);
            } else if(func_00594470(D_006C4BA0,name,256)==0) func_005A6AB0(s->name,name,256);
        }
    }
}
