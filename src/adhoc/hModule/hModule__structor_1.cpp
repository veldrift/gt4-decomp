/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int color; Node *parent; Node *left; Node *right; char pad[8]; };
struct Tree { int alloc; Node *head; int count; unsigned char cmp; };
extern char hModule__vtable[];
extern "C" void *hObject__structor_1(void *, void *);
extern "C" void *func_005EFEA0(void);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00328660(void *);
extern "C" Node *func_005EEB70(Tree *, Node *, Node *);
static inline Node *minimum(Node *x) {
    while (x->left != 0) x = x->left;
    return x;
}
static inline Node *maximum(Node *x) {
    while (x->right != 0) x = x->right;
    return x;
}
extern "C" int hModule__structor_1(char *self, char *arg1) {
    int spare[4];
    hObject__structor_1(self, arg1);
    *(char **)(self + 4) = hModule__vtable;
    *(int *)(self + 0x10) = *(int *)(arg1 + 0x10);
    void *p = *(void **)(arg1 + 0x14);
    *(void **)(self + 0x14) = p;
    if (p != 0) func_00328660(p);
    Tree *t = (Tree *)(self + 0x18);
    Tree *o = (Tree *)(arg1 + 0x18);
    t->head = 0;
    Node *n = (Node *)func_00326750(0x18, 4, *(const char **)func_005EFEA0());
    t->count = 0;
    t->head = n;
    t->cmp = o->cmp;
    if (o->head->parent == 0) {
        n->color = 0;
        t->head->parent = 0;
        t->head->left = t->head;
        t->head->right = t->head;
    } else {
        n->color = 0;
        t->head->parent = func_005EEB70(t, o->head->parent, t->head);
        Node *x = t->head->parent;
        Node **pl = &t->head->left;
        while (x->left != 0) x = x->left;
        *pl = x;
        x = t->head->parent;
        Node **pr = &t->head->right;
        while (x->right != 0) x = x->right;
        *pr = x;
    }
    t->count = o->count;
    *(void **)(self + 0x28) = 0;
}
