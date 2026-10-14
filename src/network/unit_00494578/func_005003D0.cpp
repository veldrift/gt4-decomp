/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0x9C/4]; void (*callback)(); };
struct Copy { int data[0x9C/4]; };
struct Obj { char pad[0x5A8]; Block *dst; char pad2[0x3E84-0x5AC]; Copy src; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *, int);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_00500518();
extern "C" int func_005003D0(Obj *o) {
    if (func_004F0C88(o)) {
        func_005A48D8(o->dst, 0, 0xA0);
        Block *w = o->dst;
        *(Copy *)w = o->src;
        w->callback = func_00500518;
        return func_004F0CD0(o, 0x12);
    }
}
