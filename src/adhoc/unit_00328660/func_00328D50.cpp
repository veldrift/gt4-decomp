/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[12]; int ref; Node *next; };
struct Pool { char pad[60]; int count; char pad40[8]; int used; };
extern "C" void func_00328C08(Pool *, Node *) throw();
extern "C" void func_00328B80(Pool *, Node *) throw();
extern "C" void func_00328D50(Pool *self, char *arg1) {
    Node **head = (Node **)(arg1 - 4);
    Node *node = *head;
    *head = node->next;
    node->next = (Node *)head;
    int *ref = &node->ref;
    if (--*ref == 0) {
        func_00328C08(self, node);
        func_00328B80(self, node);
    }
    self->count++;
    self->used--;
}
