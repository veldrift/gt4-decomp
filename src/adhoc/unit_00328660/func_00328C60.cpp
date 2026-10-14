/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Node { int x0; Node *prev; Node *next; u32 ref; Node **freehead; };
struct Pool { char pad[0x30]; Node *head; Node *tail; void *free; int count; u32 bytes, total, used, maxuse; };
extern "C" Node *func_00328A80(Pool *) throw();
extern "C" void func_00328BE0(Pool *, Node *) throw();
extern "C" void func_00328C08(Pool *, Node *) throw();
extern "C" void *func_00328C60(Pool *self) {
    Node *node = 0;
    if (self->count) {
        node = self->head;
        Node *head = node;
        while (node) {
            u32 ref = node->ref;
            u32 total = self->total;
            if (ref < total) {
                if (node != head && ref < total - 1) {
                    func_00328C08(self, node);
                    func_00328BE0(self, node);
                }
                break;
            }
            node = node->next;
        }
    }
    if (!node) {
        node = func_00328A80(self);
        func_00328BE0(self, node);
    }
    u32 used = self->used + 1;
    self->used = used;
    if (self->maxuse < used) self->maxuse = used;
    self->count--;
    u32 *ref = &node->ref;
    ++*ref;
    Node **p = node->freehead;
    node->freehead = (Node **)*p;
    *p = node;
    return p + 1;
}
