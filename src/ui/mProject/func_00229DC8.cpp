/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep {int len,cap,ref,sel;};
struct Str {char *p;char pad[12];};
struct Info {const char *name;};
extern char D_00698458[],D_00698460[];
extern unsigned PDISTD__LOCALE;
extern "C" void func_00229CD0(Str *,char *) throw();
extern "C" unsigned func_005DACE0(const Str *,char,unsigned);
extern "C" Str *func_005CB368(Str *,unsigned,unsigned,unsigned,char);
extern "C" const char *func_0048EDA0(unsigned);
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" int func_00485E28(char *,const char *,int,int);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline Rep *str_rep(Str *s) {return (Rep *)s->p-1;}
static inline char *rep_data(Rep *r) {return (char *)(r+1);}
static inline int str_length(Str *s) {return str_rep(s)->len;}
static inline void str_terminate(Str *s) {rep_data(str_rep(s))[str_length(s)]=0;}
static inline const char *c_str(Str *s) {if(str_length(s)==0)return D_00698458;str_terminate(s);return rep_data(str_rep(s));}
static inline void release(Str *s) {Rep *q=str_rep(s);if(--q->ref==0) {int size=q->cap+0x10;func_00326798(q,size,4,func_005C11A8()->name);}}
extern "C" void func_00229DC8(char *p) {
 Str s;char buf[128];unsigned npos=-1;func_00229CD0(&s,p);
 unsigned pos=func_005DACE0(&s,'/',npos);
 if(pos!=npos)func_005CB368(&s,pos,npos,0,0);
 const char *path=func_0048EDA0(PDISTD__LOCALE);
 func_0057DA20(buf,D_00698460,c_str(&s),path);
 func_00485E28(p+0xb0,buf,0,-1);release(&s);
}
