/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Val { int type; int spare[3]; };
struct Owner { int pad0; int *handle; char pad8[0x4c-8]; int pace, p50, p54, p58; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_00659E20;
extern char D_006A3410[], D_006A3420[], D_006A3498[], D_006A34A0[];
extern int D_00621C78[];
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" int func_003D8C18(Owner *) throw();
extern "C" void func_003DA518(int *,char *,const char *,int) throw();
extern "C" Found *func_00480878(int,Str *);
extern "C" void free(void *) throw();
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" char *GT4MC__FileGT4GameData__loadInstance(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" char *DisplayRText__getRTextStr(int);
extern "C" void func_004768C0(Val *);
extern "C" void func_00476AE8(Val *,const char *);
extern "C" int func_004809D8(char *,Str *,Val *);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659E20); strobe__Any__setMember(s,0,-1,p,func_0057F260(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_003DB520(Owner *self) {
    union { Val v; Str s; } first;
    union { char buf[32]; Str s; } second;
    Str *ps=&first.s;
    int handle=*self->handle;
    const char *name=D_006A3410;
    ps->p=grab(&D_00659E20);
    char *result=0;
    strobe__Any__setMember(ps,0,-1,name,func_0057F260(name));
    Found *found=func_00480878(handle,&first.s);
    if(found) {
        Entry *e=found->entry;
        result=GT4MC__FileGT4GameData__loadInstance(e->fn,func_00608F30,0,(char *)found+e->delta,func_00607408,found);
    }
    destroy(&first.s);
    if(result) *(int *)(result+0x74)=func_003D8C18(self);
    for(int i=1;i<8;i++) {
        func_0057DA20(second.buf,D_006A3420,i);
        int flag=0;
        switch(i) {
        case 1: case 2: case 3: case 4: case 5: flag=i==self->pace+1; break;
        case 6: flag=self->p50>0; break;
        case 7: flag=self->p54>0; break;
        }
        func_003DA518(self->handle,result,second.buf,flag);
    }
    const char *text=DisplayRText__getRTextStr(((int *)0x621C78)[self->p58]);
    if(!text) text=D_006A3498;
    first.v.type=1;
    func_00476AE8(&first.v,text);
    construct(&second.s,D_006A34A0);
    func_004809D8(result,&second.s,&first.v);
    destroy(&second.s);
    func_004768C0(&first.v);
}
