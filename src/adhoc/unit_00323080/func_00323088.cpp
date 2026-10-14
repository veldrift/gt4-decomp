/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next, *prev; int value; };
struct Iter { Node *p; Iter(Node *n):p(n) {} Iter(const Iter &o):p(o.p) {} };
struct Self { char pad[0x18]; Node *head; };
extern "C" void *func_005F1BC0(void);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00318520(void *, int);
inline Iter insert(Iter pos, int value) {
    Node *node = (Node *)func_00326750(12, 4, *(const char **)func_005F1BC0());
    int *p = &node->value;
    if (p) func_00318520(p, value);
    node->next = pos.p;
    node->prev = pos.p->prev;
    pos.p->prev->next = node;
    pos.p->prev = node;
    return Iter(node);
}
extern "C" void func_00323088(Self *self, int value) {
    insert(Iter(self->head), value);
}
