typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_00323D08(Handle *h);
extern "C" void func_00321E38(void *arg0, Handle *h, void *arg2);
extern "C" void func_00323BD0(void *p);
extern "C" void func_00323B60(Handle *h, s32 flags);

extern "C" void mUndef__virtual_09(void *self, void *arg1) {
    Handle h;
    func_00323D08(&h);
    func_00321E38(arg1, &h, (char *)self + 8);
    if (h.p != 0) {
        func_00323BD0(h.p);
    }
    func_00323B60(&h, 2);
}
