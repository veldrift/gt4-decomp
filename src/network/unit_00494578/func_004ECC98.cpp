/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,sel; };
struct Str { char *p; };
struct URL { int kind; Str user,pass,host; int port; Str path; };
extern Rep D_00659E20;
extern const char *D_00645428[];
extern int D_006C0228[];
extern const char D_006C0208[],D_006C0210[],D_006C0218[],D_006C0220[];
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" Str *func_0060DC18(Str *,u32,u32,const Str *,u32,u32);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" void free(void *) throw();
extern "C" void *func_005A48D8(void *,int,u32);
extern "C" int func_005A5A30(char *,u32,const char *,...);
static inline Rep *rep(Str *s) {return (Rep *)s->p-1;}
static inline char *grab(Rep *r) {
 if(r->sel) return strobe__toUpper(r);
 ++r->ref; return (char *)(r+1);
}
static inline void release(Str *s) {Rep *r=rep(s);if(--r->ref==0)free(r);}
static inline void init(Str *s,const char *p) {s->p=grab(&D_00659E20);strobe__Any__setMember(s,0,-1,p,func_0057F260(p));}
static inline void append(Str *s,const char *p) {u32 n=func_0057F260(p);strobe__Any__setMember(s,rep(s)->len,0,p,n);}
static inline void append(Str *s,const Str *p) {func_0060DC18(s,rep(s)->len,0,p,0,-1);}
extern "C" Str *func_004ECC98(Str *out,URL *u) {
 Str s[4],b[4],c[4]; char buf[16];
 init(s,D_00645428[u->kind]);
 append(s,D_006C0208);
 if(__builtin_expect((int)rep(&u->user)->len,0)) {
  append(s,&u->user);
  if(__builtin_expect((int)rep(&u->pass)->len,0)) {
   Str *ps=s;
   init(c,D_006C0210);
   append(c,&u->pass);
   Str *pb=b;
   pb->p=grab(rep(c));
   release(c);
   append(ps,pb);
   release(pb);
  }
  append(s,D_006C0218);
 }
 append(s,&u->host);
 if(u->port!=D_006C0228[u->kind]) {
  func_005A48D8(buf,0,16);
  func_005A5A30(buf,16,D_006C0220,u->port);
  append(s,buf);
 }
 append(s,&u->path);
 out->p=grab(rep(s));
 release(s);
 return out;
}
