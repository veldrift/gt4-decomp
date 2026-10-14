struct Node {
    Node *prev, *next;
    int f8;
    int *head;
    int pad10[3];
    void *f1c, *f20, *f24, *f28, *f2c;
};
extern Node **D_0064B70C;
extern "C" Node *func_00538988(int) throw();
extern "C" int func_00538C68(void *);
extern "C" void func_00542970(int *) throw();
extern "C" void func_00542A60(Node *, int *) throw();
extern "C" void func_005439F0(int id) {
    void *tmp;
    Node *p = func_00538988(id);
    if(p) {
        int *n = p->head;
        while(n) {
            func_00542A60(p,n);
            func_00542970(n);
            n = p->head;
        }
        if(p->f20) func_00538C68(&p->f20);
        if(p->f1c) {
            tmp = p->f1c;
            func_00538C68(&tmp);
            p->f1c = 0;
        }
        if(p->f2c) func_00538C68(&p->f2c);
        if(p->f24) func_00538C68(&p->f24);
        if(p->f28) func_00538C68(&p->f28);
        if(*D_0064B70C == p) *D_0064B70C = p->next;
        p->next->prev = p->prev;
        Node **list = D_0064B70C;
        p->prev->next = p->next;
        if(*list == p) *list = 0;
        tmp = p;
        func_00538C68(&tmp);
    }
}
