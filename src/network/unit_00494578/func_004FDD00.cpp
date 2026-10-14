/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0xAC/4]; };
struct Obj { char pad[0x5A8]; Block *dst; char pad2[0xA44-0x5AC]; Block src; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *, int);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_004FDD00(Obj *o) {
    if (func_004F0C88(o)) {
        func_005A48D8(o->dst, 0, 0xC4);
        *o->dst = o->src;
        return func_004F0CD0(o, 0x4B);
    }
}
