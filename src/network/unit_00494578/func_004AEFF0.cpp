struct Pair{int a,b;Pair(){a=0;b=0;}};
inline void clear(Pair*p){p->a=0;p->b=0;}
struct S{char pad[0x30];int a,b,c;char x[12];int d,e,f;char y[12];int g;Pair p,q;int h,i,j,k;char z[20];int l,m,n,o;void*vt;};
extern "C" char D_00688ED0[];
extern "C" void func_00574D78(void*);
extern "C" void func_0060AD28(void*,void*);
extern "C" void func_004AF6B8(void*);
extern "C" void func_004AEFF0(S*s){s->vt=D_00688ED0;func_00574D78(s);s->a=0;s->b=0;s->c=0;func_0060AD28(s->x,s);s->d=0;s->e=0;s->f=0;func_0060AD28(s->y,s);s->g=0;Pair*q=&s->q;clear(&s->p);clear(q);s->h=2;s->j=5;s->i=0;s->k=0;func_004AF6B8(s->z);s->l=0;s->m=0;s->n=0;s->o=0;}
