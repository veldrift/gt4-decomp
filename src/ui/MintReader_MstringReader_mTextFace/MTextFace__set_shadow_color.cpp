typedef int s32;

struct Str {
    s32 p;
    s32 pad[3];
    s32 get() const { return p; }
};

extern "C" void func_002434C8(void *arg0, void *arg1);
extern "C" void func_00203678(void *arg0, void *arg1);
extern "C" void *func_002030E8(void *arg0, void *arg1);
extern "C" void func_00203620(void *arg0, int arg1);
extern "C" void func_00243470(void *arg0, int arg1);

extern "C" void func_00244080(void *arg0, void *arg1, int argc, void *name)
{
    if (argc > 0) {
        Str s;
        func_002434C8(&s, arg1);
        Str t;
        func_00203678(&t, name);
        func_002030E8((void *)(s.get() + 0xE0), (void *)(t.get() + 0x10));
        func_00203620(&t, 2);
        func_00243470(&s, 2);
    }
}
