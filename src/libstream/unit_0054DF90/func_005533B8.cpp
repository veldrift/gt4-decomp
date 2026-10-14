/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[8]; void *p8; int padc; void *p10; char pad14[0x40]; int magic; int flags; int pad5c; void *p60; void (*cb)(); int pad68; char data[0x20]; };
extern "C" void func_00553580();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void *exception__structor_0(int);
extern "C" void rbuf__structor_0(void *, int);
extern "C" void func_005547E8(void *);
extern "C" void func_00565A78(void *);
extern "C" void func_00565798(void *, int);
extern "C" void func_00565AD0(void *);
extern "C" void func_005533B8(Obj *o) {
    void **handle = &o->p8;
    o->magic = 0x534d5550;
    o->flags = 1;
    o->cb = func_00553580;
    o->p10 = 0;
    func_005A48D8(o->data, 0, 0x20);
    void *p = exception__structor_0(0x44);
    rbuf__structor_0(p, 0x20);
    *handle = p;
    func_005547E8(p);
    func_00565A78(o);
    func_00565798(o->p60, 0);
    func_00565AD0(o);
}
