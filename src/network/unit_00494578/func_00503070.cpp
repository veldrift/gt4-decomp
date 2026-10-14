/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; void (*fn)(char *); };
struct VT { char pad[0x20]; VE e; };
struct Obj { char pad[0x48]; VT *vt; };
struct Node { Obj *obj; int pad; Node *next; };
struct List { Node *head; };
extern "C" void func_00503070(void *self, List *list) {
    Node *n = list->head;
    if (n != 0) {
        do {
            VE *e = &n->obj->vt->e;
            e->fn((char *)n->obj + e->adj);
            n = n->next;
        } while (n != 0);
    }
}
