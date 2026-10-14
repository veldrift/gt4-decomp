/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char *vt; };
struct Tgt { char *vt; };
struct Entry { short delta,index; Tgt *(*fn)(void *,int); };
struct Out { int a,b; float c; };
extern "C" void func_003FC4F0(char *,int);
extern "C" int func_003FD620(char *,char *,char *,int,int *);
extern "C" int func_003FD5A8(char *,char *,int);
extern "C" void func_00377898(Obj *,char *,char *,int,unsigned,Out *);
extern "C" void func_00377968(Obj *,char *,char *,int,unsigned,Out *);
extern "C" void func_00377A60(Obj *,char *,char *,int,unsigned,Out *);
extern "C" void func_00377170(Obj *,char *,char *,int,unsigned,Out *,int);
extern "C" void func_00378F28(Tgt *,char *,char *,char *,char *);
extern "C" void func_003852A0(char *,float);
extern "C" float func_00385370(char *);
static inline Tgt *get(Obj *self,int idx) {
    Entry *e=(Entry *)(self->vt+0xD8);
    return e->fn((char *)self+e->delta,idx);
}
extern "C" void func_003751F0(Obj *self,char *ctx,char *other,int idx,unsigned flags,Out *out) {
    int buf[4];
    char *base=(char *)self+idx*0x19C;
    char *p=base+0x10;
    char *fp=base+0xE0;
    float scale=1.0f;
    float value=0.0f;
    if (*(unsigned char *)(fp+0x1E)) value=scale;
    char *spring=base+0x14C;
    func_003852A0(spring,value);
    float raw=func_00385370(spring)*3.0f;
    float lo=scale;
    scale=raw+scale;
    if (scale<=lo) scale=lo;
    if (scale>=4.0f) scale=4.0f;
    int changed=0;
    if (*(unsigned char *)((char *)self+0xC24) && *(int *)((char *)self+0xC2C)%900==0) {
        int count=**(int **)(ctx+0x60);
        int max=count-1;
        int next=*(int *)((char *)self+0xC28)+1;
        next%=count;
        if (next<0) next=0;
        if (max<next) next=max;
        *(int *)((char *)self+0xC28)=next;
        if (*(short *)(p+0xC)!=next) {
            changed=1;
            func_003FC4F0(p,next);
            out->c=0.5f;
        }
    }
    int next=*(int *)(p+0x18C);
    if (next>=0 && *(short *)(p+0xC)!=next) {
        changed=1;
        func_003FC4F0(p,next);
    }
    signed char direction=*(signed char *)(fp+0x1F);
    if (direction!=0) {
        if (func_003FD5A8(ctx,p,direction>0)) changed=1;
    }
    if (changed) {
        flags|=2;
        out->b=1;
    }
    switch (func_003FD620(ctx,other,p,0,buf)) {
    case 1: func_00377898(self,ctx,other,idx,flags,out); break;
    case 2: func_00377968(self,ctx,other,idx,flags,out); break;
    case 3: func_00377A60(self,ctx,other,idx,flags,out); break;
    default:
        if (get(self,idx)==*(Tgt **)(p+0x158)) flags|=2;
        func_00377170(self,ctx,other,idx,flags,out,0);
        break;
    }
    Tgt *t=get(self,idx);
    *(float *)((char *)t+0x14C)=scale;
    func_00378F28(t,ctx,fp,p,(char *)self+0x9C0);
}
