/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xAC]; int x; };
struct Node { char pad[0x38]; Obj *owner; char pad3c[12]; int handle; };
extern "C" void func_004AC5D0(void *);
extern "C" Node *func_004AC660();
extern "C" int func_004AC778(int);
extern "C" int func_004AC798(int);
extern "C" void func_004AC7B8(int);
extern "C" void func_004AD300(void *, void *);
extern "C" int func_004AE908(int, const char *);
extern "C" void func_004AEAE8(int, int);
extern "C" int func_0057F260(const char *) throw();
extern "C" Node *func_004B1730(Obj *arg0, const char *arg1, Node *arg2) {
    Node *node = arg2;
    if (node) {
        func_004AC5D0(node);
        node->owner = arg0;
    } else {
        node = func_004AC660();
        if (!node) return node;
        node->owner = arg0;
    }
    int h = func_004AC778(func_0057F260(arg1) + 2);
    node->handle = h;
    int p = func_004AC798(h);
    func_004AEAE8(p, func_004AE908(arg0->x, arg1));
    func_004AC7B8(h);
    func_004AD300(arg0, node);
    return node;
}
