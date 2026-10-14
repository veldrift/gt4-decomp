/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Name { const char *name; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
extern Rep D_00659FA8;
extern "C" void func_0015F3E0(void *,void *) throw();
extern "C" void func_0015F388(void *,int) throw();
extern "C" void func_002EFC48(void *,int);
extern "C" s32 *HArray__operator_index(void *,int);
extern "C" void func_002ED5C0(void *,int);
extern "C" void func_002FC870(void *,int);
extern "C" void func_002FE278(void *,s32);
extern "C" void func_00312318(void *,int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(void *,int,int,const char *,int);
extern "C" Name *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline void assign(s32 *dst,s32 *src) {
    if(dst!=src) { s32 n=*src; if(n) func_003285A8(n); s32 o=*dst; if(o) func_003285F8(o); *dst=n; }
}
static inline void release(Str *s) {
    Rep *q=(Rep *)(s->p-16);
    if(--q->ref==0) { s32 size=q->cap+16; func_00326798(q,size,4,func_005C11A8()->name); }
}
extern "C" void MGame__getEntryCarCode(s32 *arg0,void *arg1,int arg2,Obj **arg3) {
    s32 buf0[4]; s32 buf1[4]; Str str;
    if(arg2>0) {
        func_0015F3E0(buf0,arg1);
        Obj *o=*arg3;
        VEntry *e=(VEntry *)(o->vtbl+0x58);
        char *data=*(char **)((char *)buf0[0]+0x10);
        data+=e->fn((char *)o+e->delta)*0x68;
        func_0015F388(buf0,2);
        func_002EFC48(buf0,2);
        char *rec=data+0xD8;
        s32 *dst=HArray__operator_index(buf0,0);
        char *p=data+0xE0;
        Str *ps=&str;
        Rep *r=&D_00659FA8;
        char *d;
        if(r->sel) d=func_005C2560(r);
        else { d=(char *)(r+1); r->ref++; }
        ps->p=d;
        func_005C2630(ps,0,-1,p,func_0057F260(p));
        p=(char *)buf1;
        func_00314B20(p,ps);
        assign(dst,(s32 *)p);
        func_00312318(p,2);
        release(ps);
        dst=HArray__operator_index(buf0,1);
        func_002FE278(p,*(s32 *)(rec+0x48));
        assign(dst,(s32 *)p);
        func_002FC870(p,2);
        assign(arg0,buf0);
        func_002ED5C0(buf0,2);
    }
}
