/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; Node *prev; int value; };
struct Obj { char pad[0x1c]; Node *head; int state; };
struct It {
    Node *node;
    It(Node *p) : node(p) {}
    It(const It &o) : node(o.node) {}
    bool operator!=(const It &o) const { return node != o.node; }
    It operator++(int) { It tmp(*this); node = node->next; return tmp; }
};
extern "C" void func_0022FB60(void *);
extern "C" void func_00250B98(char *, void *) throw();
extern "C" int func_00251BD0(void *) throw();
extern "C" int func_00251BD8(void *, int) throw();
extern "C" int mEvent__GetClassID();
extern "C" void func_00251C08(Obj *self) {
    int i = 0;
    int n = func_00251BD0(self);
    for (; i < n; i++) func_0022FB60((void *)func_00251BD8(self, i));
    self->state = 1;
    func_00250B98((char *)self, (void *)mEvent__GetClassID());
    It first(self->head->next);
    It last(self->head);
    while (first != last) { first.node->value = 0; first++; }
}
