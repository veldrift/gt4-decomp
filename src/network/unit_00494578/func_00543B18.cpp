typedef int s32;
typedef unsigned int u32;
struct Node { char pad0[4]; Node *next; char pad8[8]; u32 key; };
extern Node **D_0064B70C;
extern "C" void func_005439F0(u32, Node *) throw();
extern "C" void func_00543B18(u32 arg0) {
    Node *n = *D_0064B70C;
    while (n != 0) {
        u32 k = n->key;
        if ((arg0 == 0xFFFFFFFF && k == arg0)
            || (arg0 == 0x80000000 && k == (k & 0x7FFFFFFF) + arg0)
            || (arg0 == 0 && k == (k & 0x7FFFFFFF))) {
            func_005439F0(k, n);
            n = *D_0064B70C;
        } else {
            n = n->next;
            if (n == *D_0064B70C) n = 0;
        }
    }
}
