extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" char D_00655340[];

struct Obj {
    char pad[0x2AA8];
    void *head;
};

struct Node {
    char pad[0xC];
    void *next;
};

extern "C" void func_0055C808(Obj *arg0, Node *arg1) {
    void *lock = D_00655340;
    func_00576100(lock);
    arg1->next = arg0->head;
    arg0->head = arg1;
    func_00576140(lock);
}
