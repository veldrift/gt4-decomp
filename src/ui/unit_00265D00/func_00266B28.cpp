/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; Node *prev; int value; };
struct It {
    Node *p;
    It(Node *q):p(q) {}
    bool operator!=(const It &b) const {return p!=b.p;}
    int &operator*() const {return p->value;}
    It &operator++() {p=p->next;return *this;}
    It operator++(int) {It t=*this; ++*this;return t;}
};
struct CIt {
 Node *p;
 CIt(Node *q):p(q) {}
 bool operator!=(const CIt &b) const {return p!=b.p;}
 CIt &operator++() {p=p->next;return *this;}
};
static inline void dist(CIt a,CIt b,unsigned int &n) {while(a!=b) {++a;++n;}}
static inline void distance(CIt a,CIt b,unsigned int &n) {dist(a,b,n);}
struct List {
 int pad; Node *head;
 It begin() {return head->next;}
 CIt begin() const {return head->next;}
 CIt end() const {return head;}
 unsigned int size() const {unsigned int n=0;distance(begin(),end(),n);return n;}
};
struct Obj {char pad[0x60];List list;};
extern "C" void func_001FF1A0(void *);
extern "C" void func_001FEF38(void *,void *);
static inline void advance(It &it,int n) { for(int i=0;i<n;i++) it++; }
extern "C" void *func_00266B28(void *out,Obj *self,int index) {
    List *list;
    if(index>=0) {
        list=&self->list;
        if((unsigned int)index<list->size()) goto found;
    }
    func_001FF1A0(out);return out;
found:
    It it=list->begin();
    for(int i=0;i<index;i++) it++;
    func_001FEF38(out,&*it);
    return out;
}
