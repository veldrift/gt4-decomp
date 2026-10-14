/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { void *next; void *prev; };
template<class T, class R, class P> struct Iter {
    typedef Iter<T,T&,T*> iterator;
    Node *node;
    Iter(Node *p) : node(p) {}
    Iter() {}
    Iter(const iterator &o) : node(o.node) {}
    bool operator!=(const Iter &o) const { return node != o.node; }
    Iter &operator++() { node = (Node *)node->next; return *this; }
};
struct Tag {};
template<class I> static inline Tag category(const I &) { return Tag(); }
template<class I, class D> static inline void distance_inner(I first, I last, D &n, Tag) {
    while (first != last) { ++first; ++n; }
}
template<class I, class D> static inline void distance(I first, I last, D &n) {
    distance_inner(first, last, n, category(first));
}
struct List {
    typedef Iter<int,const int&,const int*> It;
    int pad; Node *head;
    It begin() const { return (Node *)head->next; }
    It end() const { return head; }
    unsigned int size() const { unsigned int n = 0; distance(begin(), end(), n); return n; }
};
struct Obj { char pad[0xCC]; List list; };
extern "C" unsigned int func_00250F30(Obj *self) { return self->list.size(); }
