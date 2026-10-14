/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Node {
    int link : 13;
    unsigned kind : 3;
    unsigned rest : 16;
    char pad[0x3C];
};
struct Pool {
    Node *recs;
    u16 head;
    short idx;
};
extern "C" int func_003E79F8(Pool *) throw();
extern "C" void func_003E96B8(Node *, void *);
extern "C" int func_0045B140(void *);
extern "C" void GT4Model__BinStreamReader__read8u(void *);
extern "C" void func_0045B620(void *, void *);
extern "C" void func_0045B740(void *, void *);

inline int allocate(Pool *p) {
    int i;
    if(p->idx<0) i=func_003E79F8(p);
    else {
    i=p->idx;
    Node *node=(Node *)((i<<6)+(int)p->recs);
    p->idx=node->link;
    node->link=p->head;
    p->head=i;
    }
    return i;
}
extern "C" void func_003E92A8(Pool *p, void *stream, int kind) {
    int buf[4];
    func_0045B620(buf, stream);
    GT4Model__BinStreamReader__read8u(stream);
    int n=func_0045B140(stream);
    for(int count=0;count<n;count++) {
        int index=allocate(p);
        Node *node=p->recs+index;
        func_003E96B8(node,stream);
        node->kind=kind;
    }
    func_0045B740(buf,stream);
}
