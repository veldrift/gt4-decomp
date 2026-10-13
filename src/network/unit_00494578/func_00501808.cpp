typedef int s32;

struct Node {
    void *val;
    char pad[4];
    Node *next;
};

extern "C" void func_005018D0(void *arg0, void *arg1);
extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);

extern "C" void func_00501808(void *arg0, void **arg1)
{
    s32 sp[4];
    Node *n;

    sp[0] = (s32)((char *)arg0 + 8);
    func_00576788(sp[0]);
    n = (Node *)*arg1;
    if (n != 0) {
        do {
            void *v = n->val;
            n = n->next;
            func_005018D0(arg0, v);
        } while (n != 0);
    }
    func_005767C0(sp[0]);
}
