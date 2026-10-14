/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0xB0/4]; };
struct Obj { char pad[0x5A8]; Block *dst; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *, int);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_004FE4C0(Obj *o, Block *src) {
    if (func_004F0C88(o)) {
        func_005A48D8(o->dst, 0, 0xB0);
        *o->dst = *src;
        return func_004F0CD0(o, 0x4E);
    }
}
