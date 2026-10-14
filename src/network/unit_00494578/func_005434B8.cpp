struct Node { char pad[0x18]; char *data; };
extern "C" void *func_00538988(int) throw();
extern "C" int func_005428E8(void *) throw();
extern "C" Node *func_00542A28(void *, unsigned) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_005434B8(int arg, unsigned index, void *dst) {
    void *head = func_00538988(arg);
    if (head == 0) return -1;
    if (dst == 0) return -1;
    Node *n = func_00542A28(head, index);
    if (n == 0 || func_005428E8(n->data) != 0) {
        func_005A48D8(dst, 0, 0x40);
        return -1;
    }
    func_005A4724(dst, n->data, 0x40);
    return 0;
}
