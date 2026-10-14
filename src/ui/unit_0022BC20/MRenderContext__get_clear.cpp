struct Target { char pad[0x128]; int flag; };
struct Owner { char pad[0x10]; Target *target; };
struct Slot { short delta; short pad; int (*fn)(void *); };
struct Obj { int pad; Slot *vt; };
extern "C" void func_0022ACC8(void *, int) throw();
extern "C" void *func_0022AD20(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void MRenderContext__get_clear(void **out, void *arg1, int n, Obj **args) {
    Owner *a[4];
    void *b[4];
    if (n == 0) {
        func_0022AD20(a, arg1);
        void **pb = b;
        func_002FE278(pb, a[0]->target->flag != 0);
        if (out != pb) {
            void *value = pb[0];
            if (value) func_003285A8(value);
            void *old = out[0];
            if (old) func_003285F8(old);
            out[0] = value;
        }
        func_002FC870(pb, 2);
        func_0022ACC8(a, 2);
        return;
    }
    if (n > 0) {
        func_0022AD20(a, arg1);
        Obj *obj = args[0];
        Target *target = a[0]->target;
        Slot *slot = obj->vt + 11;
        target->flag = slot->fn((char *)obj + slot->delta) != 0;
        func_0022ACC8(a, 2);
    }
}
