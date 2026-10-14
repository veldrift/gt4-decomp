/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, res, ref, selfish; };
struct Heap { const char *name; };
struct Str;
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, u32, u32, const char *);
extern "C" Str *func_005C2630(Str *, u32, u32, const char *, u32);
extern "C" Str *func_005CE388(Str *, u32, u32, const Str *, u32, u32);
static inline char *grab(Rep *r) { if (r->selfish) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
static inline void deallocate(void *p, u32 n) { func_00326798(p,n,4,func_005C11A8()->name); }
static inline void rep_delete(void *p) { deallocate(p,sizeof(Rep)+((Rep *)p)->res); }
static inline void release(Rep *r) { if (--r->ref == 0) rep_delete(r); }
struct Str {
 char *dat;
 Rep *rep() const { return (Rep *)dat-1; }
 Str() { dat=grab(&D_00659FA8); }
 Str(const char *s) { dat=grab(&D_00659FA8); func_005C2630(this,0,-1,s,func_0057F260(s)); }
 Str(const Str &s) { dat=grab(s.rep()); }
 ~Str() { release(rep()); }
 Str &operator=(const Str &s) { if (&s!=this) { release(rep()); dat=grab(s.rep()); } return *this; }
 Str &operator+=(const Str &s) { return *func_005CE388(this,rep()->len,0,&s,0,-1); }
};
struct Pipe { char pad[0x18]; int len; };
struct Face { char pad[0xbc]; Pipe *pipe; char padc0[0x64]; int first,last; Str text[128]; signed char count[128]; };
extern "C" int func_00227B70(Pipe *, char *, int);
extern "C" void func_002E57D8(Face *, int *, int, int) throw();
extern "C" int func_002E5810(Face *self) {
 char buf[0x101];
 if (!self->pipe) return 0;
 int len=self->pipe->len;
 int n=func_00227B70(self->pipe,buf,0x101);
 if (n<=0) return 0;
 buf[n]=0;
 int count=0;
 int line=-1;
 if (self->last!=self->first) {
  line=self->last;
  func_002E57D8(self,&line,128,-1);
 } else {
  self->text[self->last]=Str();
  self->count[self->last]=1;
  count=1;
  line=self->last;
  func_002E57D8(self,&self->last,128,1);
  if (self->last==self->first) func_002E57D8(self,&self->first,128,1);
 }
 for (int i=0;i<len;i++) {
  int start=i;
  while (buf[i]!='\n' && i<len) i++;
  if (buf[i]=='\n') {
   buf[i]=0;
   self->text[line]+=Str(buf+start);
   self->text[self->last]=Str();
   self->count[self->last]=1;
   count++;
   line=self->last;
   func_002E57D8(self,&self->last,128,1);
   if (self->last==self->first) func_002E57D8(self,&self->first,128,1);
  } else {
   self->text[line]+=Str(buf+start);
  }
 }
 return count;
}
