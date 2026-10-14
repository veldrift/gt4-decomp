typedef struct State { char pad0[8]; char name[256]; char other[256]; unsigned offset; int failed; } State;
extern char D_006C49C8[],D_006C4B98[];
typedef struct Names { const char *entries[4]; } Names;
extern Names D_006C4BB8;
const char *func_0053F398(char *,unsigned);
int func_00594470(const char *,const char *,unsigned);
void func_005401B0(State *,const char *,int);
void func_00540020(const char *text,int len,State *s) {
    int i=0;
    Names table=D_006C4BB8;
    if(s->failed==0 && len!=0 && *text!=' ') {
        const char *path=func_0053F398(s->other,s->offset);
        for(;table.entries[i]!=0;i++) {
            if(func_00594470(table.entries[i],path,256)==0) break;
        }
        switch((unsigned)i) {
        case 0:
            if(func_00594470(D_006C49C8,s->name,256)!=0) s->failed=1;
            else if(*text!='1') s->failed=1;
            break;
        case 1:
            if(func_00594470(D_006C49C8,s->name,256)!=0) s->failed=i;
            else if(*text!='0') { s->failed=i; return; }
            break;
        case 2: {
            const char *tag=D_006C4B98;
            char *p=s->name;
            if(func_00594470(tag,p,256)==0) {
                func_005401B0(s,text,len);
                *p=0;
            }
            break;
        }
        }
    }
}
