/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int color; Node *parent; Node *left; Node *right; char pad[8]; };
struct Tree { int alloc; Node *head; int count; unsigned char cmp; };
extern char hModule__vtable[];
extern "C" void *hObject__structor_0(void *);
extern "C" void *func_005EFEA0(void);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void hModule__structor_0(char *self, int *arg1) {
    int spare[4];
    hObject__structor_0(self);
    *(char **)(self + 4) = hModule__vtable;
    *(int *)(self + 0x10) = *arg1;
    *(int *)(self + 0x14) = 0;
    Tree *t = (Tree *)(self + 0x18);
    t->head = 0;
    Node *n = (Node *)func_00326750(0x18, 4, *(const char **)func_005EFEA0());
    t->count = 0;
    t->head = n;
    t->cmp = 0;
    n->color = 0;
    t->head->parent = 0;
    t->head->left = t->head;
    t->head->right = t->head;
    *(int *)(self + 0x28) = 0;
}
