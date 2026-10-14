
struct Rep {int len,cap,ref,sel;};
struct Str {char *p;};
struct Info {const char *name;};
extern Rep D_00659FA8;
extern char D_00697FF0[];
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_002ED5C0(void *,int);
extern "C" void func_0023A538(void *,void *,void *,Str *,void *);
extern "C" void func_002319A0(void *,void *);
extern "C" void func_00239F08(void *,int);
struct Obj {int word;char *vt;};
struct Movie {char pad[0x104];int paused;char p108[0xc];Obj *movie;char name[0x40];int frame;int skip;};
static inline int vi(Obj *p,int off){struct E {short d,i;int (*fn)(void *);};E *e=(E *)(p->vt+off);return e->fn((char *)p+e->d);}
static inline void init(Str *ps,const char *src){Rep *r=&D_00659FA8;char *d;if(r->sel)d=func_005C2560(r);else{d=(char *)(r+1);r->ref=r->ref+1;}ps->p=d;func_005C2630(ps,0,-1,src,func_0057F260(src));}
static inline void destroy(Str *s){Rep *q=(Rep *)(s->p-0x10);if(--q->ref==0){int n=q->cap+0x10;func_00326798(q,n,4,func_005C11A8()->name);}}
extern "C" void mMovieFace__virtual_69(Movie *self,void *ctx){
 int result[12];
 if(self->skip==0){Obj **pm=&self->movie;if(*pm){
 if(self->frame>=0){if(vi(*pm,0xa0)==self->frame){
 Str s;int payload[12];Str *ps=&s;const char *src=self->name;
 init(ps,src);int *p=payload;func_002EFBF0(p);
 func_0023A538(result,ctx,self,ps,p);func_002319A0(ctx,result);func_00239F08(result,2);func_002ED5C0(p,2);destroy(ps);self->frame=-1;
 }}
 if(self->paused==0 && vi(*pm,0x98)!=0){
 Str s;int payload[4];Str *ps=&s;const char *src=D_00697FF0;
 init(ps,src);int *p=payload;func_002EFBF0(p);
 func_0023A538(result,ctx,self,ps,p);func_002319A0(ctx,result);func_00239F08(result,2);func_002ED5C0(p,2);destroy(ps);
 }
 }}
}
