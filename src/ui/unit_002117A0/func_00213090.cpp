/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[0x10]; const void *key; void *val; };
struct H;
extern "C" void func_002556B0(H *);
extern "C" void func_002550A0(H *,const H *);
extern "C" void func_002550B8(H *,int);
extern "C" void *func_00263368(H *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct H {
 void *p;
 H() { func_002556B0(this); }
 H(const H &h) { func_002550A0(this,&h); }
 H(void *o) { func_00263368(this,o); }
 ~H() { func_002550B8(this,2); }
 H &operator=(const H &h) {
  if (this != &h) {
   void *v=h.p;
   if(v) func_003285A8(v);
   if(p) func_003285F8(p);
   p=v;
  }
  return *this;
 }
};
struct It { Node *node; It() {} It(Node *n):node(n) {}
 bool operator!=(const It &o) const { return node != o.node; }
 Node *operator->() const { return node; } };
struct Tree;
extern "C" It func_005D9050(Tree *,const void *);
struct Tree { int count; Node *header;
 It find(const void *k) { return func_005D9050(this,k); }
 It end() { return It(header); } };
struct Self { char pad[16]; Tree tree; };
extern "C" H func_00213090(Self *self,const void *key) {
 H h;
 It it = self->tree.find(key);
 if (it != self->tree.end()) h = H(it->val);
 return h;
}
