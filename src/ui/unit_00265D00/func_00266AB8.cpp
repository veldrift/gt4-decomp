/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {void *next,*prev; void *data;};
struct It {
 Node *node;
 It(Node *n):node(n) {}
 It() {}
 It(const It &i):node(i.node) {}
};
struct CIt {
 Node *node;
 CIt(Node *n):node(n) {}
 CIt(const It &i):node(i.node) {}
 bool operator==(const CIt &i) const { return node==i.node; }
 bool operator!=(const CIt &i) const { return node!=i.node; }
 CIt &operator++(){node=(Node *)node->next;return *this;}
};
template<class I,class D> inline void distance2(I first,I last,D &n) {
 while(first!=last) {++first;++n;}
}
template<class I,class D> inline void distance1(I first,I last,D &n) {
 distance2(first,last,n);
}
struct List {
 int alloc; Node *node;
 CIt begin() const {return (Node *)node->next;}
 CIt end() const {return node;}
 unsigned size() const {unsigned n=0;distance1(begin(),end(),n);return n;}
};
extern "C" unsigned func_00266AB8(char *self) {
 return ((List *)(self+0x60))->size();
}
