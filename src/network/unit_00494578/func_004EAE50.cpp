/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, sel; char *data(){return (char *)(this+1);} char *grab(); void release(); };
extern Rep D_00659E20;
extern char D_006BFFD0[], D_006BFF30[], D_006C0088[], D_006C0138[], D_006C0148[], D_006C0150[], D_006C0158[], D_006C0170[], D_006C0178[], D_006C0188[];
#define D_006BFFD0 "\r\n"
#define D_006C0088 ": "
#define D_006C0138 "Set-Cookie"
struct Str;
extern "C" char *strobe__toUpper(Rep *);
extern "C" void free(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" int func_005A2F88(const char *) throw();
extern "C" int func_005A5AD8(const char *,const char *,...) throw();
extern "C" void func_00574D18(const char *,...);
extern "C" void func_004EA4B0(void *,void *) throw();
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" Str *func_0060DC18(Str *,u32,u32,const Str *,u32,u32);
extern "C" Str *func_00605888(Str *,u32,u32,u32,char);
extern "C" u32 func_0060DEE0(const Str *,const char *,u32,u32);
extern "C" int func_005FBDD0(const Str *,const char *,u32,u32);
inline char *Rep::grab(){ if(sel) return strobe__toUpper(this); ++ref; return data(); }
inline void Rep::release(){ if(--ref==0) free(this); }
struct Str {
 char *dat;
 Rep *rep() const { return (Rep *)dat-1; }
 Str(const Str &s):dat(s.rep()->grab()){}
 Str(const Str &s,u32 pos,u32 n):dat(D_00659E20.grab()){func_0060DC18(this,0,-1,&s,pos,n);}
 Str(const char *s):dat(D_00659E20.grab()){strobe__Any__setMember(this,0,-1,s,func_0057F260(s));}
 ~Str(){rep()->release();}
 void init(){dat=D_00659E20.grab();}
 void copy(const Str &s){dat=s.rep()->grab();}
 void release(){rep()->release();}
 const char *c_str() const { if(!rep()->len)return D_006BFF30; dat[rep()->len]=0; return dat; }
 u32 find(const char *s) const {return func_0060DEE0(this,s,0,func_0057F260(s));}
 int compare(const char *s) const {return func_005FBDD0(this,s,0,func_0057F260(s));}
};
static inline void substring(Str *const d,const Str *s,u32 pos,u32 n) { d->init(); func_0060DC18(d,0,-1,s,pos,n); }
static inline void literal(Str *const d,const char *s) { d->init(); strobe__Any__setMember(d,0,-1,s,func_0057F260(s)); }
struct Node { char pad[20]; Str val; };
struct Iter { Node *node; char pad[12]; Iter(){} Iter(Node *p):node(p){} Iter(const Iter &s):node(s.node){} };
struct Pair; struct Result;
struct Tree { int alloc; Node *end; int size; Iter finish(){return Iter(end);} Iter find(const Str &s); Result insert(const Pair &p); };
struct Pair { Str a,b; Pair(const Str &x,const Str &y):a(x),b(y){} };
struct Result { Node *node; int flag; Result(const Result &); };
extern "C" void func_0060D9A0(Iter *,Tree *,const Str *);
extern "C" Result func_0060DA68(Tree *,const Pair &);

inline Result Tree::insert(const Pair &p){return func_0060DA68(this,p);}
static inline bool operator!=(const Iter &a,const Iter &b){return a.node!=b.node;}
struct Cursor { Node *node; char pad[12]; };
static inline bool different(const Cursor &a,const Cursor &b){return a.node!=b.node;}
struct Obj { char pad0[0x54]; Str body; char pad58[0x18]; Tree headers; char pad7c[0x54]; int ready,chunk,done,left,total,read,status; };
extern "C" int func_004EAE50(Obj *o) {
 int more=1;
 while(more && !o->ready) {
  unsigned pos=o->body.find(D_006BFFD0);
  if(pos==0) o->ready=1;
  else if(pos!=(u32)-1) {
   Str line(o->body,0,pos);
   func_00605888(&o->body,0,pos+2,0,0);
   pos=line.find(D_006C0088);
   if(pos!=(u32)-1) {
    Str key(line,0,pos);
    Str value(line,pos+2,-1);
    if(key.compare(D_006C0138)==0) func_004EA4B0(o,&value);
    else o->headers.insert(Pair(key,value));
   } else {
    func_00574D18(D_006C0148,line.c_str());
    func_00605888(&line,0,line.find(D_006C0150)+1,0,0);
    func_00605888(&line,line.find(D_006C0150),-1,0,0);
    o->status=func_005A2F88(line.c_str());
   }
  } else more=0;
 }
 if(o->ready) {
  Iter ret; Cursor it; struct Temp {char *dat;char pad[12];} t; Cursor it2; Temp t2;
  Cursor *i=&it;
  Tree *tree=&o->headers;
  Str *s=(Str *)&t;
  literal(s,D_006C0158);
  func_0060D9A0(&ret,tree,s); i->node=ret.node;
  { Rep *r=(Rep *)s->dat; --r; if(--r->ref==0) free(r); } ((Iter *)s)->node=tree->end;
  int chunk=0;
  if(i->node!=((Iter *)s)->node) chunk=i->node->val.compare(D_006C0170)==0;
  if(chunk) { o->chunk=1; o->done=0; o->left=0; o->total=0; o->read=0; }
  else {
   o->chunk=0; o->done=0;
   func_00605888(&o->body,0,2,0,0);
   Cursor *j=&it2; Str *s2=(Str *)&t2;
   literal(s2,D_006C0178);
   func_0060D9A0(&ret,tree,s2); j->node=ret.node;
   { Rep *r=(Rep *)s2->dat; --r; if(--r->ref==0) free(r); } ((Iter *)s2)->node=tree->end;
   if(different(*j,*(Cursor *)s2)) func_005A5AD8(j->node->val.c_str(),D_006C0188,&o->total);
   else o->total=0;
   o->read=o->total;
   if(!o->total)return 1;
  }
 }
 return 0;
}
