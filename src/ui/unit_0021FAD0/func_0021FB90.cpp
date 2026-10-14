/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep {int len,cap,ref,sel;};
struct Str {char *p;};
struct Info {const char *name;};
struct Obj {int word;char *vt;};
struct Movie {char pad[0xf0];Str name;char p[0x20];Obj *movie;};
extern "C" char *func_005C2560(Rep *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline void destroy(Str *s){Rep *q=(Rep *)(s->p-0x10);if(--q->ref==0){int n=q->cap+0x10;func_00326798(q,n,4,func_005C11A8()->name);}}
static inline char *grab(char *d){Rep *r=(Rep *)(d-0x10);if(r->sel)return func_005C2560(r);r->ref=r->ref+1;return d;}
static inline bool present(Obj *p){return p != 0;}
extern "C" void func_0021FB90(Movie *self,Str *src){
 Str *dst=&self->name;
 if(src!=dst){destroy(dst);dst->p=grab(src->p);}
 Obj *p=self->movie;if(present(p)){struct E {short d,i;void (*fn)(void *,Str *);};E *e=(E *)(p->vt+0x50);e->fn((char *)p+e->d,dst);}
}
