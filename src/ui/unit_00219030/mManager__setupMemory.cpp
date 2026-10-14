/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int x; char *vt; };
struct Handle { Obj *p; char pad[12]; };
struct Self { char pad[0x28]; int x28,x2c; };
struct VE { short d,i; Handle *(*fn)(void *,unsigned); };
struct VI { short d,i; int (*fn)(void *); };
extern char D_0082B570[],D_0082BBB8[],D_0082C200[],D_0082C848[];
extern "C" void func_002EFBF0(Handle *);
extern "C" int func_0032A570(Handle *,const char *);
extern "C" unsigned hArray__size(Obj *);
extern "C" void func_00329280(void *,unsigned,int);
extern "C" int func_00326660(void *);
extern "C" void func_002ED5C0(Handle *,int);
extern "C" int func_00327908();
static inline int get(Obj *o) {
    VI *e=(VI *)(o->vt+0x58);
    return e->fn((char *)o+e->d);
}
static inline Handle *at(Obj *o,unsigned i) {
    VE *e=(VE *)(o->vt+0x70);
    return e->fn((char *)o+e->d,i);
}
#define BODY(str,glob) { \
    func_002EFBF0(&h); \
    if(func_0032A570(&h,str)) { \
        for(unsigned i=0;i<20 && i<hArray__size(h.p);i++) \
            func_00329280(glob,i,get(at(h.p,i)->p)); \
    } \
    self->x28=func_00326660(glob); \
    func_002ED5C0(&h,2); \
}
extern "C" void mManager__setupMemory(Self *self,int arg1) {
    Handle h;
    if(arg1==0) BODY("HugeAllocatorRelease",D_0082B570)
    else if(arg1==1) BODY("LargeAllocatorRelease",D_0082BBB8)
    else if(arg1==2) BODY("SmallAllocatorRelease",D_0082C200)
    else if(arg1==3) BODY("TinyAllocatorRelease",D_0082C848)
    self->x2c=func_00327908();
}
