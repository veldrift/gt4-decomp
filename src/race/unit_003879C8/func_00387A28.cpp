/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Item {
    const char *name;
    s32 pad4;
    s32 (*fn8)(void);
    s32 (*fnC)(void *, s32);
};
struct Node {
    Node *next;
    Item *item;
};
extern Node *D_00621314;
extern "C" s32 func_0057F238(const char *, const char *) throw();

extern "C" s32 func_00387A28(const char *arg0, void *arg1, s32 arg2) {
    Node *n = D_00621314;
    while (n != 0) {
        if (func_0057F238(arg0, n->item->name) == 0) {
            if (arg1 == 0) {
                return n->item->fn8();
            }
            return n->item->fnC(arg1, arg2);
        }
        n = n->next;
    }
    return 0;
}
