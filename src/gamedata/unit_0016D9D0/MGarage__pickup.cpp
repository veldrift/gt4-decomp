/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct H {void *p; int pad[3];};
struct Str {char *p; int pad[3];};
struct Rep {int len,cap,ref,sel;};
struct Name {const char *name;};
struct Obj {int pad; char *vt;};
struct VE {short delta,index; void (*fn)(Str *,void *);};
extern char D_00690A30[];
extern char D_00690A38[];
extern "C" Name *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" int func_00448E28(const char *);
extern "C" int func_00448DC8(const char *);
extern "C" int func_00145F70(const char *);
extern "C" void func_0016D848(H *,void *) throw();
extern "C" void func_0016D7F0(H *,int) throw();
extern "C" H *func_00170088(H *,void *,int,int,int);
extern "C" void func_002ED5C0(H *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00690A30;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}
static inline void vstr(Str *s,Obj *o) {
 VE *e=(VE *)(o->vt+24);
 e->fn(s,(char *)o+e->delta);
}
extern "C" void MGarage__pickup(H *ret,void *arg1,int n,Obj **args) {
 union {Str s; H h;} u;
 H garage;
 int a=-1;
 int b=-1;
 int c=-1;
 const char *text;
 if(n>0) {
  vstr(&u.s,args[0]);
  text=c_str(&u.s);
  release(&u.s);
  if(func_0057F238(text,D_00690A38)!=0) a=func_00448E28(text);
 }
 if(n>=2) {
  vstr(&u.s,args[1]);
  text=c_str(&u.s);
  release(&u.s);
  if(func_0057F238(text,D_00690A38)!=0) b=func_00448DC8(text);
 }
 if(n>=3) {
  vstr(&u.s,args[2]);
  text=c_str(&u.s);
  release(&u.s);
  if(func_0057F238(text,D_00690A38)!=0) c=func_00145F70(text);
 }
 H *pg=&garage;
 func_0016D848(pg,arg1);
 func_00170088(&u.h,pg->p,a,b,c);
 if(ret!=&u.h) {
  void *p=u.h.p;
  if(p)func_003285A8(p);
  if(ret->p)func_003285F8(ret->p);
  ret->p=p;
 }
 func_002ED5C0(&u.h,2);
 func_0016D7F0(pg,2);
}
