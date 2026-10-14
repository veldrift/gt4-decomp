/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Small { char pad[0x40]; char name[0x30]; };
struct Big { char pad[0xd0]; char name[0x100]; };
struct Conn { char pad[0x44]; Small *small; Big *big; char pad4c[8]; int nsmall; int nbig; };
extern "C" int func_004EDC38(Conn *,int,const char *,const char *) throw();
extern "C" const char *func_004EE6B8(Conn *,int);
extern "C" const char *func_004EE6F0(Conn *,int);
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_004EE140(Conn *self,const char *name,const char *text) {
    int i;
    for(i=0;i<self->nsmall;i++) {
        if(func_0057F238(self->small[i].name,text)!=0) continue;
        const char *s=func_004EE6B8(self,i);
        const char *t=func_004EE6F0(self,i);
        int j;
        int r=func_004EDC38(self,0,name,text);
        if(r>=0 && s) {
            if(func_0057F260(s)) {
                r=func_004EDC38(self,1,name,s)>=0;
                if(r && t) {
                    if(!func_0057F260(t)) return r;
                    j=0;
                    if(self->nsmall>0) {
                    loop:
                        if(j==i) goto increment;
                        if(func_0057F238(func_004EE6F0(self,j),t)!=0) goto increment;
                    done:
                        return r;
                    increment:
                        j++;
                        if(j<self->nsmall) goto loop;
                    }
                    r=func_004EDC38(self,2,name,t);
                }
            }
        }
        goto done;
    }
    for(i=0;i<self->nbig;i++) {
        if(!func_0057F238(self->big[i].name,text)) return func_004EDC38(self,1,name,text);
    }
    return -1;
}
