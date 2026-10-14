/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int color; Node *parent; Node *left; Node *right; char pad[12]; };
struct Tree { int alloc; Node *head; int count; unsigned char cmp; };
extern char mUpdateContextPS2__vtable[];
extern "C" void *mUpdateContext__structor_0(void *);
extern "C" void func_00574D78(void *);
extern "C" void func_0055F9F8(void *);
extern "C" void MenuControl__structor_0(void *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_00105250(char *);
extern "C" void *func_005DA140();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void mUpdateContextPS2__structor_0(char *self) {
    int spare[4];
    Tree *t = (Tree *)(self + 0x424);
    mUpdateContext__structor_0(self);
    *(char **)(self + 4) = mUpdateContextPS2__vtable;
    func_00574D78(self + 0x130);
    func_0055F9F8(self + 0x160);
    MenuControl__structor_0(self + 0x1A0);
    MenuControl__structor_0(self + 0x274);
    func_005A48D8(self + 0x348, 0, 0x10);
    func_005A48D8(self + 0x358, 0, 0x8C);
    func_00105250(self + 0x3E4);
    *(int *)(self + 0x420) = 0;
    t->head = 0;
    Node *n = (Node *)func_00326750(0x1C, 4, *(const char **)func_005DA140());
    t->count = 0;
    t->head = n;
    t->cmp = 0;
    n->color = 0;
    t->head->parent = 0;
    t->head->left = t->head;
    t->head->right = t->head;
}
