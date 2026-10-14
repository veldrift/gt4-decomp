/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Alloc { const char *name; };
struct Obj { char pad[0x104]; Str key; };
extern Rep D_00659FA8;
extern char D_006992B8[],D_006992C8[],D_006992D0[],D_006992F0[];
extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *);
extern "C" void *func_005C2630(Str *,s32,s32,const char *,s32);
extern "C" void func_005CE388(Str *,s32,s32,Str *,s32,s32);
extern "C" Alloc *func_005C11A8();
extern "C" void func_00326798(void *,s32,s32,const char *);
extern "C" s32 func_0025A7E0(Str *,Obj *);
extern "C" char *func_0026A4D0(char *,Str *);
extern "C" void func_0026A118(Str *,s32);
extern "C" void func_005DB110(const char *,...);
extern "C" void func_0024A198(Obj *);
static inline Rep *rep(Str *s) { return (Rep *)s->p-1; }
static inline void release(Str *s) { Rep *q=rep(s); if(--q->ref==0) { s32 size=q->cap+16; func_00326798(q,size,4,func_005C11A8()->name); } }
static inline char *grab(Rep *r) { if(r->sel) return func_005C2560(r); char *d=(char *)(r+1); s32 n=r->ref+1; r->ref=n; return d; }
static inline void construct(Str *s,const char *src) { s->p=grab(&D_00659FA8); func_005C2630(s,0,-1,src,func_0057F260(src)); }
static inline void assign(Str *dst,Str *src) { if(src!=dst) { release(dst); dst->p=grab(rep(src)); } }
static inline char *data(Rep *r) { return (char *)(r+1); }
static inline s32 length(Str *s) { return rep(s)->len; }
static inline void terminate(Str *s) { data(rep(s))[length(s)]=0; }
static inline const char *c_str(Str *s) { if(length(s)==0) return D_006992C8; terminate(s); return data(rep(s)); }
extern "C" void mToolTipFace__setKey(Obj *o,Str *key) {
    if(*(s32 *)((char *)o+0x108)==0) {
        if(rep(key)->len!=0) {
            Str result;
            Str tmp;
            Str *ps=&tmp;
            construct(ps,D_006992B8);
            func_005CE388(ps,rep(ps)->len,0,key,0,-1);
            result.p=grab(rep(ps));
            release(ps);
            func_0025A7E0(ps,o);
            char *text=func_0026A4D0(ps->p,&result);
            func_0026A118(ps,2);
            if(text) {
                Str *dst=(Str *)((char *)o+0x104);
                construct(ps,text);
                assign(dst,ps);
                release(ps);
            } else {
                func_005DB110(D_006992D0,D_006992F0,0x98,c_str(&result));
                assign((Str *)((char *)o+0x104),key);
            }
            release(&result);
        }
        func_0024A198(o);
    }
}
