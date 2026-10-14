/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Holder { void *p; char pad[12]; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct VObj { int x; char *vt; };
struct Str { char *p; };
struct Handle { VObj *p; };
struct Self { char pad[0xf0]; Str str[8]; Handle h[8]; };
extern "C" void func_00210710(void *,int);
extern "C" void func_0025A7E0(void *,void *);
extern "C" void func_0026A118(void *,int);
extern "C" void func_0026A990(void *,void *,void *,int,int,int);
extern "C" void mImageFace__virtual_67(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline int vc58(VObj *o) {
    VEntry *e=(VEntry *)(o->vt+0x58);
    return e->fn((char *)o+e->delta);
}
static inline void assign(Handle *d, Holder *s) {
    if((void *)d != (void *)s) {
        VObj *v=(VObj *)s->p;
        if(v) func_003285A8(v);
        if(d->p) func_003285F8(d->p);
        d->p=v;
    }
}
static inline bool empty(Str *s) { return ((Rep *)s->p)[-1].len == 0; }
#define LOAD(i,k) { \
    Str *np=&self->str[i]; \
    if(!empty(np)) { \
        Handle *d=&self->h[i]; \
        if(d->p==0 || vc58(d->p)==0) { \
            Holder *ph=&h[k]; \
            func_0025A7E0(ph,self); \
            func_0026A990(&tmp,ph->p,np,1,0,1); \
            assign(d,&tmp); \
            func_00210710(&tmp,2); \
            func_0026A118(ph,2); \
        } \
    } \
}
extern "C" void mFrameImageFace__virtual_67(Self *self) {
    Holder tmp;
    Holder h[7];
    mImageFace__virtual_67(self);
    LOAD(0,0)
    LOAD(1,1)
    LOAD(2,2)
    LOAD(3,3)
    LOAD(4,4)
    LOAD(5,5)
    LOAD(6,6)
    LOAD(7,0)
}
