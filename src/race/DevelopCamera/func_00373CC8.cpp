struct Node { char pad[0x1A8]; int value; };
struct Item { Node *node; char pad[0x19C - 4]; };
struct Obj { char pad[0x15C]; Item items[6]; };
extern "C" void func_00373CC8(Obj *o, int v) {
    int i;
    for (i = 0; i < 6; i++) {
        Item *it = &o->items[i];
        Node *n = it->node;
        if (n)
            n->value = v;
    }
}
