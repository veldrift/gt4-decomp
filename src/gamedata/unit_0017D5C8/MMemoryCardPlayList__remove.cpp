/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[16]; void *list; int pad14; int dirty; };
struct VE { short delta; short index; int (*fn)(void *); };
struct VO { int x; VE *vt; };
static inline int vcall(VO *o) {
    VE *e = (VE *)((char *)o->vt + 0x58);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_0017D268(void *, int) throw();
extern "C" void func_0017D2C0(void *, void *) throw();
extern "C" void func_001D12D8(void *, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void MMemoryCardPlayList__remove(void **arg0, void *arg1, int arg2, VO **arg3) {
    Node *h[4];
    void *buf[4];
    bool result = false;
    func_0017D2C0(h, arg1);
    if (arg2 > 0) {
        int index = vcall(*arg3);
        if (index >= 0) {
            func_001D12D8(h[0]->list, index);
            h[0]->dirty = 1;
            result = true;
        }
    }
    void **p = buf;
    func_002FE278(p, result);
    if (arg0 != p) {
        void *n = *p;
        if (n != 0) func_003285A8(n);
        void *old = *arg0;
        if (old != 0) func_003285F8(old);
        *arg0 = n;
    }
    func_002FC870(p, 2);
    func_0017D268(h, 2);
}
