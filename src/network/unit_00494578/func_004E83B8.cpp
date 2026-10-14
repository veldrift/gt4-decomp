/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,sel; char *data() { return (char *)(this+1); } char *grab(); void release(); };
struct Str;
extern Rep D_00659E20;
extern char D_006BFF38[],D_006BFF40[];
extern "C" char *strobe__toUpper(Rep *);
extern "C" void free(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" Str *func_0060DC18(Str *,u32,u32,const Str *,u32,u32);
inline char *Rep::grab() { if(sel) return strobe__toUpper(this); ++ref; return data(); }
inline void Rep::release() { if(--ref==0) free(this); }
struct Str {
 char *p;
 Rep *rep() const { return (Rep *)p-1; }
 u32 length() const { return rep()->len; }
 Str():p(D_00659E20.grab()) {}
 Str(const Str &s):p(s.rep()->grab()) {}
 ~Str() { rep()->release(); }
 Str &append(const Str &s) { return *func_0060DC18(this,length(),0,&s,0,-1); }
 Str &append(const char *s,u32 n) { return *strobe__Any__setMember(this,length(),0,s,n); }
 Str &append(const char *s) { return append(s,func_0057F260(s)); }
};
struct Node { bool color; Node *parent,*left,*right; };
struct Value { Str first,second; };
struct VNode:Node { Value value; };
struct ItBase {
 Node *n;
 void increment() {
  if(n->right!=0) { n=n->right; while(n->left!=0) n=n->left; }
  else { Node *y=n->parent; while(n==y->right) { n=y; y=y->parent; } if(n->right!=y) n=y; }
 }
};
struct It:ItBase {
 It() {}
 It(Node *x) { n=x; }
 const Value &operator*() const { return ((VNode *)n)->value; }
 It operator++(int) { It tmp=*this; increment(); return tmp; }
};
inline bool operator!=(const ItBase &a,const ItBase &b) { return a.n!=b.n; }
struct Map { int alloc; Node *header; u32 count; It begin() const { return It(header->left); } It end() const { return It(header); } };
struct Obj { char pad[0x80]; Map map; };
extern "C" Str func_004E83B8(const Obj *obj) {
 Str s;
 for(It it=obj->map.begin();it!=obj->map.end();) {
  s.append((*it).first);
  s.append(D_006BFF38);
  s.append((*it).second);
  it++;
  if(it!=obj->map.end()) s.append(D_006BFF40);
 }
 return s;
}
