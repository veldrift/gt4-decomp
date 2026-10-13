/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry {
    char pad[0x2C];
    s32 id;
};

struct Node {
    Entry *entry;
    s32 pad4;
    Node *next;
};

extern "C" void *func_005012A8(Node **arg0, s32 arg1) {
    Node *n;

    for (n = *arg0; n != 0; n = n->next) {
        if (n->entry->id == arg1) {
            return n;
        }
    }
    return 0;
}
