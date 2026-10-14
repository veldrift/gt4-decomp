/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { int ref; char *vt; };
struct H { Obj *p; };
struct H16 { H h; char pad[12]; };
struct Vec { int alloc; H *begin, *end, *cap; char pad[16]; };
struct Iter { H *p; char pad[12]; };
struct Stk { char pad[0x14]; H *arr; char pad2[8]; int count; };
struct Ctx { char pad[0x2c]; Stk *stk; };
struct Self { char pad[8]; int count; };
struct Info { const char *name; };
struct VE { short delta,index; void (*fn)(void *, H *); };
struct GetE { short delta,index; H *(*fn)(void *, int); };
struct SetE { short delta,index; void (*fn)(void *, int, H *); };
extern "C" void func_00309378(void *, int);
extern "C" void *func_0030BB18(void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" int func_002ED660(void *, H *);
extern "C" int hArray__size(Obj *);
extern "C" void func_002EF9C8(Obj *, unsigned);
extern "C" void func_002EFBF0(void *);
extern "C" void *func_002EFC48(void *, int);
extern "C" void *func_00326750(unsigned, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_003285A8(Obj *);
extern "C" void func_003285F8(Obj *);
extern "C" Info *HObject__tf();
extern "C" H *func_005D84B0(H *, int, H *, int);
static inline Obj *deref(H *h) { return h->p; }
static inline H *at(Vec *v,int i) { return v->begin+i; }
static inline H *pop(Stk *s) { return s->arr + --s->count; }
static inline void assign(H *d, H *s) {
    if(d != s) { Obj *n=s->p; if(n)func_003285A8(n); Obj *o=d->p; if(o)func_003285F8(o); d->p=n; }
}
static inline void set(Obj *o,int i,H *h) { SetE *e=(SetE *)(o->vt+0x78); e->fn((char *)o+e->delta,i,h); }
static inline void put(Obj *o,H *h) { VE *e=(VE *)(o->vt+0x90); e->fn((char *)o+e->delta,h); }
static inline H *get(Obj *o,int i) { GetE *e=(GetE *)(o->vt+0x70); return e->fn((char *)o+e->delta,i); }
static inline void putget(Obj *o,Obj *src,int i) { VE *e=(VE *)(o->vt+0x90); void *p=(char *)o+e->delta; H *h=get(src,i); e->fn(p,h); }
static inline void setget(Obj *o,int j,Obj *src,int i) { SetE *e=(SetE *)(o->vt+0x78); void *p=(char *)o+e->delta; H *h=get(src,i); e->fn(p,j,h); }
static inline void putnil(Obj *o,H *h) { VE *e=(VE *)(o->vt+0x90); void *p=(char *)o+e->delta; func_0030BB18(h); e->fn(p,h); func_00309378(h,2); }
static inline void deallocate(H *p,int n) {
    if(p)func_00326798(p,n*4,4,HObject__tf()->name);
}
static inline void release(Vec *v) { deallocate(v->begin,v->cap-v->begin); }
static inline void init(Vec *v,int count,Iter *it) {
    v->begin=0;v->end=0;v->cap=0;
    H *base=(H *)func_00326750(count*4,4,HObject__tf()->name);
    v->cap=base+count; it->p=base; v->end=base; v->begin=base;
}
static inline H *value_type(H *const *) { return 0; }
static inline void destroy_aux(H *first,H *end,H *) {
    for(;first!=end;++first)func_00309378(first,2);
}
static inline void destroy_range(H *first,H *end,Iter *it) {
    it->p=first;
    destroy_aux(it->p,end,value_type(&it->p));
}
static inline void destroy(Vec *v,Iter *it) {
    destroy_range(v->begin,v->end,it);
    release(v);
}
extern "C" void mListAssign__execute(Self *self,Ctx *ctx) {
    Vec v;
    Iter it;
    H16 h;
    H16 tmp;
    H *src=pop(ctx->stk);
    int count=self->count;
    init(&v,count,&it);
    func_0030BB18(&h);
    v.end=func_005D84B0(it.p,count,&h.h,0);
    func_00309378(&h,2);
    for(int i=self->count-1;i>=0;--i) assign(v.begin+i,pop(ctx->stk));
    func_002EFBF0(&h);
    if(!func_002ED660(&h,src)) {func_002EF9C8(deref(&h.h),1);set(deref(&h.h),0,src);}
    int n=v.end-v.begin;
    int m=hArray__size(deref(&h.h));
    if(n>0) {
        if(n==m) {
            for(int i=0;i<n;i++)putget(deref(at(&v,i)),deref(&h.h),i);
        } else if(m<n) {
            int i=0;
            for(;i<m;i++)putget(deref(at(&v,i)),deref(&h.h),i);
            for(;i<n;i++)putnil(deref(at(&v,i)),&tmp.h);
        } else if(n<m) {
            int last=n-1;
            int i=0;
            for(;i<last;i++)putget(deref(at(&v,i)),deref(&h.h),i);
            func_002EFC48(&tmp,m-n+1);
            for(;i<m;i++)setget(deref(&tmp.h),i-n+1,deref(&h.h),i);
            put(deref(at(&v,last)),&tmp.h);
            func_002ED5C0(&tmp,2);
        }
    }
    Stk *s=ctx->stk;
    assign(s->arr+s->count,&h.h);
    s->count++;
    func_002ED5C0(&h,2);
    destroy(&v,&it);
}
