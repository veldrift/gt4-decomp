struct Node { char pad[0x18]; int handle; };
extern "C" int func_00538830(void *);
extern "C" void *func_00538988(int) throw();
extern "C" Node *func_00542A28(void *, unsigned) throw();
extern "C" int func_005428E8(int) throw();
extern "C" void func_00542DA8(int,int,void *,int) throw();
extern "C" unsigned func_00546CA0(void *,void *,const unsigned char *,unsigned char *,unsigned);
extern "C" int func_00543798(int id,unsigned index,void *a,void *b,unsigned char *data) {
    void *obj;
    Node *n;
    if (data == 0) goto fail;
    if (func_00538830(a) != 0) return -1;
    if (func_00538830(b) != 0) goto fail;
    obj = func_00538988(id);
    if (obj == 0) return -1;
    n = func_00542A28(obj, index);
    if (n == 0) return -1;
    if (func_005428E8(n->handle) == 0) goto success;
fail:
    return -1;
success:
    func_00542DA8(n->handle, 4, data, 0x40);
    func_00546CA0(a, b, data, data, 0x40);
    return 0;
}
