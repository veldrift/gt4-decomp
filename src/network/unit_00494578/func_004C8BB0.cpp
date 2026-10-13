typedef int s32;

struct D_Node {
    char pad0[4];
    D_Node *child;   /* +0x4 */
    char pad1[4];
    D_Node *next;    /* +0xC */
};

extern "C" void func_004C8C38(s32, void *);

extern "C" void func_004C8BB0(s32 arg0, D_Node *node) {
    if (node) {
        do {
            D_Node *child = node->child;
            D_Node *next = node->next;
            if (child) {
                func_004C8C38(arg0, child);
            }
            func_004C8C38(arg0, node);
            node = next;
        } while (node);
    }
}
