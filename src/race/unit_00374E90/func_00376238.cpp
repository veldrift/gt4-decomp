/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
struct Obj { char *vt; };
struct Tgt { char *vt; char p4[0x184]; float f188; int i18C; char p190[0xD0]; u64 f260, f268; };
struct GetEnt { short delta,index; Tgt *(*fn)(void *, int); };
struct IntEnt { short delta,index; int (*fn)(void *); };
struct VoidEnt { short delta,index; void (*fn)(void *); };
struct InitEnt { short delta,index; void (*fn)(void *, char *, int); };
struct FloatEnt { short delta,index; void (*fn)(void *, int, float); };
extern "C" int func_003FF688(int, int *, int);
extern "C" float func_00578598(void *);
extern "C" void func_0037BC48(Tgt *, int, int);
extern "C" void func_00379FA8(Tgt *, float, int);
static inline Tgt *get(Obj *self, int idx) {
    GetEnt *e=(GetEnt *)(self->vt+0xD8);
    return e->fn((char *)self+e->delta,idx);
}
static inline int kind(Tgt *t) {
    IntEnt *e=(IntEnt *)(t->vt+0xB8);
    return e->fn((char *)t+e->delta);
}
static inline float affine(float x, float a, float b) { return x*a+b; }
extern "C" int func_00376238(Obj *self, int idx, int a2, char *ctx, void *rng, float time) {
    int buf[26];
    int old = -1;
    Tgt *t=*(Tgt **)((char *)self+idx*0x19C+0x158);
    if (get(self,idx)==t) {
        if (t->i18C==*(int *)(ctx+0x10)) old=kind(t);
    }
    int n=func_003FF688(*(int *)(ctx+0x10),buf,26);
    float r=func_00578598(rng);
    int choice=0;
    if (!(r<0x1.333332p-2f)) {
        choice=5;
        if (!(r<0x1.333332p-1f) && n>0) {
            int j=(int)(func_00578598(rng)*(float)n);
            int max=n-1;
            if (j<=0) j=0;
            if (j>=max) j=max;
            choice=buf[j];
        }
    }
    InitEnt *init=(InitEnt *)(t->vt+0x140);
    init->fn((char *)t+init->delta,ctx,choice);
    VoidEnt *v=(VoidEnt *)(t->vt+0x170);
    v->fn((char *)t+v->delta);
    t->f268=(t->f268 & ~0xFFul)|1;
    FloatEnt *f=(FloatEnt *)(t->vt+0x150);
    f->fn((char *)t+f->delta,3,time);
    if (kind(t)==old) func_0037BC48(t,old+1,1);
    int k=kind(t);
    if (k==0 || k==5) {
        r=func_00578598(rng);
        r=affine(r,20.0f,60.0f);
        t->f260=(t->f260 & 0x00FFFFFFFFFFFFFFul)|0x100000000000000ul;
        t->f188=r;
        if (func_00578598(rng)<0.5f) t->f268=(t->f268 & ~0xFF00ul)|0x100ul;
    }
    if (func_00578598(rng)<0x1.999998p-2f) {
        int flag=1;
        switch (kind(t)) {
        case 0: case 5: case 14 ... 17: flag=0; break;
        default: break;
        }
        func_00379FA8(t,time,flag);
    }
    if (func_00578598(rng)<0x1.333332p-2f) {
        int k=kind(t);
        if (k==0 || k==5) t->f260=(t->f260 & 0xFFFF00FFFFFFFFFFul)|0x10000000000ul;
    }
    *(Tgt **)((char *)self+idx*0x19C+0x13C)=t;
    return 1;
}
