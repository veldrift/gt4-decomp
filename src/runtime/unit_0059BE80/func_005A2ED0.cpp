typedef int s32;

extern "C" s32 func_00575DC8(s32 arg0);

struct Node {
    Node *next;
    s32 count;
    s32 items[32];
};

struct Obj {
    char pad[0x148];
    Node *head;
    Node node;
};

extern Obj *D_00658288;

extern "C" s32 func_005A2ED0(s32 arg0) {
    Obj **g;
    Node *n;
    s32 *pc;
    s32 c;

    g = &D_00658288;
    n = (*g)->head;
    if (n == 0) {
        n = &(*g)->node;
        (*g)->head = n;
    }
    if (n->count >= 0x20) {
        n = (Node *)func_00575DC8(0x88);
        if (n == 0) {
            return -1;
        }
        n->count = 0;
        n->next = (*g)->head;
        (*g)->head = n;
    }
    pc = &n->count;
    c = *pc;
    *pc = c + 1;
    n->items[c] = arg0;
    return 0;
}
