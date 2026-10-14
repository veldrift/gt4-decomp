struct Sub { char pad[12]; int c, d, e; };
struct Obj { char pad[0x100]; Sub *sub; int id; char pad2[0x60]; int a,b,c,d; };
struct Global { char pad[0x104]; int a,b,c,d,e,f,g,h,i,j,k,l,m; };
extern Global D_00854038;
extern Global *D_0064B4B4;
extern "C" {
int func_00534990(Obj *, int);
int func_00536568(int);
int func_00532588(Obj *, int, int, int, unsigned char *);
void func_00518C80() throw();
int func_005164D0() throw();
void func_0051B9F0(Obj *);
void func_005310D0(Obj *, unsigned int);
Obj *func_00535A18(unsigned int);
int func_00518B58(Obj *, int) throw();
}
extern "C" int func_00518D28(Obj *o) {
    unsigned char buf;
    if (!o) return 0x17;
    Global *g=&D_00854038;
    if (!g->f) return 0x10;
    func_00534990(o,0);
    buf=func_00536568(o->id);
    func_00532588(o,-1,0x12,1,&buf);
    func_00518C80();
    func_005164D0();
    func_0051B9F0(o);
    g->f=0;
    Sub *s=o->sub;
    Global *q=D_0064B4B4;
    q->b=0;
    q->c=0;
    if (!s) return 0x17;
    s->c=2;
    s->d=0;
    s->e=0;
    func_005310D0(o,-1);
    for (int i=0;i<4;i++) {
        Obj *r=func_00535A18(i);
        if (r) {
            func_00518B58(r,0x100);
            o->a=0; o->b=0; o->c=0; o->d=0;
        }
    }
    Global *q2=D_0064B4B4;
    Global *t=&D_00854038;
    t->i=0;
    q2->m=0;
    t->h=0;
    t->a=0;
    q2->k=0; q2->l=0; q2->j=0;
    return 0;
}
