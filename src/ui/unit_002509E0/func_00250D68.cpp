/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next, *prev; int value; };
struct List { int alloc; Node *head; };
struct Frame { int buf[4]; Node *result; int pad1[3]; Node *pos; int pad2[3]; int copy; int pad3[3]; };
extern "C" void *func_00254088(void *, void *);
extern "C" void *func_002540A0(void *, void *);
extern "C" void func_002540B8(void *, int);
extern "C" void *func_005DD870(void);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00250D68(char *self, int value) {
    Frame f;
    List *list = (List *)(self + 0xCC);
    f.copy = value;
    func_00254088(f.buf, &f.copy);
    f.pos = list->head;
    Node *node = (Node *)func_00326750(12, 4, *(const char **)func_005DD870());
    int *p = &node->value;
    if (p) func_002540A0(p, f.buf);
    node->next = f.pos;
    node->prev = f.pos->prev;
    f.pos->prev->next = node;
    f.pos->prev = node;
    f.result = node;
    func_002540B8(f.buf, 2);
}
