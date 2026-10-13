typedef int s32;

struct D_Node {
    char pad[0x18];
    D_Node *child;   /* +0x18 */
    D_Node *next;    /* +0x1C */
};

extern "C" void func_004C8C38(s32, void *);

extern "C" void func_004C8B50(s32 arg0, D_Node *node) {
    if (node) {
        do {
            D_Node *child = node->child;
            if (child) {
                func_004C8C38(arg0, child);
            }
            D_Node *next = node->next;
            func_004C8C38(arg0, node);
            node = next;
        } while (node);
    }
}
