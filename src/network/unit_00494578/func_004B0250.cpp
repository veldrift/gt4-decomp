/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_0088FFC0[],D_00688FE0[];
struct Pair { int a,b; };
static inline void init(Pair *p) { p->a=0; p->b=0; }
struct S { char pad[0x44]; void *vt; char gap[0x3248]; int x,y,z; Pair p,q; };
extern "C" void *func_004ADEE0(void *,void *);
extern "C" void func_00574D78(void *);
extern "C" int func_004B0250(S *s) {
    struct { void *p; int n; } t;
    t.p=D_0088FFC0; t.n=0x8000;
    func_004ADEE0(s,&t);
    s->vt=D_00688FE0;
    func_00574D78((char *)s+0x3170);
    func_00574D78((char *)s+0x31A0);
    func_00574D78((char *)s+0x31D0);
    func_00574D78((char *)s+0x3200);
    func_00574D78((char *)s+0x3230);
    func_00574D78((char *)s+0x3260);
    s->x=0; Pair *p=&s->p; s->y=0;
    init(p); init(&s->q);
}
