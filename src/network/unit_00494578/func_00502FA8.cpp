typedef int s32;

struct Node {
    Node *next;
    char pad[4];
};

struct Obj {
    char pad0[0x98];
    Node *list;
};

extern "C" void func_00574EE8(void *arg0);
extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);

extern "C" void func_00502FA8(Obj *self)
{
    s32 sp[4];
    Node *n;
    Node *next;

    sp[0] = (s32)((char *)self + 0x68);
    func_00576788(sp[0]);
    n = self->list;
    self->list = 0;
    while (n != 0) {
        next = n->next;
        func_00574EE8((char *)n + 4);
        n = next;
    }
    func_005767C0(sp[0]);
}
