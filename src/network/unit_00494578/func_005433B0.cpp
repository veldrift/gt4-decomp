typedef int s32;
struct Node { char pad[8]; s32 id; s32 x; void *a; void *b; void *c; };
extern "C" void *func_00538988(s32) throw();
extern "C" int func_005428E8(void *) throw();
extern "C" Node *func_00542A28(void *, s32) throw();
extern "C" Node *func_00542928() throw();
extern "C" void func_005429F0(void *, Node *) throw();
extern "C" int func_00538B08(void *, int) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_00546830(void *, void *);
extern "C" int func_005433B0(s32 arg0, s32 arg1, void *arg2) {
    void *head = func_00538988(arg0);
    if (!head) return -1;
    if (func_005428E8(arg2)) return -1;
    Node *node = func_00542A28(head, arg1);
    if (!node) {
        node = func_00542928();
        node->id = arg1;
        func_005429F0(head,node);
    }
    if (!node->c) func_00538B08(&node->c,0x40);
    if (!node->a) func_00538B08(&node->a,0x10c);
    if (!node->b) func_00538B08(&node->b,0x10c);
    func_005A4724(node->c,arg2,0x40);
    func_00546830(node->a,arg2);
    func_00546830(node->b,arg2);
    return 0;
}
