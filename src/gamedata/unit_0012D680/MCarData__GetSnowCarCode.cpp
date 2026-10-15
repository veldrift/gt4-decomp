/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
union U { Str s; void *h[4]; };
struct Heap { const char *name; };
struct VEntry { short delta, index; void (*fn)(void *,void *); };
struct Obj { int word; char *vt; };
extern Rep D_00659FA8;
extern char D_0068E7F8[], D_0068E848[];
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_005C2630(void *,unsigned int,unsigned int,const char *,unsigned int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_00312318(void *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" int func_00448AD0(const char *,void *);
extern "C" int func_00447CA0(long long,char *);
static inline Rep *rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *data(Rep *r) { return (char *)(r+1); }
static inline int length(Str *s) { return rep(s)->len; }
static inline void terminate(Str *s) { data(rep(s))[length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (length(s)==0) return D_0068E7F8;
    terminate(s);
    return data(rep(s));
}
static inline void release(Str *s) {
    Rep *r=rep(s);
    if (--r->ref == 0) {
        int size = r->cap+16;
        func_00326798(r,size,4,func_005C11A8()->name);
    }
}
static inline void empty(Str *s) {
 Rep *r=&D_00659FA8; char *p;
 if(r->sel) p=func_005C2560(r);
 else { r->ref=r->ref+1; p=(char *)(r+1); }
 s->p=p;
}
static inline void vcall(void *ret,Obj *o) {
 VEntry *e=(VEntry *)(o->vt+0x18); e->fn(ret,(char *)o+e->delta);
}
#define ASSIGN() if(dst!=u.h) { newVal=u.h[0]; if(newVal)func_003285A8(newVal); oldVal=*dst; if(oldVal)func_003285F8(oldVal); *dst=newVal; } func_00312318(&u,2)
extern "C" void MCarData__GetSnowCarCode(void **dst,int count,Obj **args) {
 U u; long long record[10];
 union Work { char buf[0x90]; struct { char spare[16]; Str s; } e; } work;
 Str a,b; Str *ps;
 void *newVal,*oldVal;
 if(count>0) {
  vcall(&u,*args);
  const char *label=c_str(&u.s); release(&u.s);
  if(func_00448AD0(label,record)) {
   char *buf=work.buf;
   if(func_00447CA0(record[8],buf)) {
    ps=&a; empty(ps); func_005C2630(ps,0,-1,buf,func_0057F260(buf));
    func_00314B20(&u,ps); ASSIGN(); release(ps);
   } else {
    ps=&b; empty(ps); func_005C2630(ps,0,-1,label,func_0057F260(label));
    func_00314B20(&u,ps); ASSIGN(); release(ps);
   }
  } else {
   const char *text=D_0068E848; ps=&work.e.s;
   empty(ps); func_005C2630(ps,0,-1,text,func_0057F260(text));
   func_00314B20(&u,ps); ASSIGN(); release(ps);
  }
 }
}
