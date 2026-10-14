/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00213B68(void *);
struct Callback { void (*fn)(void *); void *self; char pad[0x18]; };
struct Args { int a; int b; char pad[8]; };
extern void *D_00619030;
extern "C" int func_00578B50(unsigned int, int);
extern "C" void *func_00578610(void *);
extern "C" void *func_00578968(void *, void *, void *);
extern "C" int func_005788B8(void *);
extern "C" void mUpdateContextPS2__virtual_49(char *self, int a, int b) {
    Callback cb;
    Args args;
    *(int *)(self + 0xE4) = 0;
    cb.fn = func_00213B68;
    cb.self = self;
    Args *p = &args;
    p->a = a;
    p->b = b;
    void *r = func_00578968(&cb, p, func_00578610((void *)func_00578B50(1, 1)));
    D_00619030 = r;
    func_005788B8(r);
}
