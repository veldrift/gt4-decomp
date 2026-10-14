/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int head[10]; int value28; char pad[0xCC-0x2C]; int valueCC; int tail; };
struct Obj { char pad0[0x40]; int value40; char pad1[0x5A8-0x44]; Block *dst; };
extern "C" int func_004F0C88(void *) throw();
extern "C" int func_004F0CD0(void *, int) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_005A6AB0(void *, void *, int) throw();
extern "C" int func_004F5F38(Obj *o, Block *src) {
    if (func_004F0C88(o)) {
        func_005A48D8(o->dst, 0, 0xD4);
        Block *w = o->dst;
        func_005A6AB0((char *)w + 0x15, (char *)o + 0xAF8, 0x11);
        *w = *src;
        int value = o->value40;
        w->valueCC = 0;
        w->value28 = value;
        return func_004F0CD0(o, 0x2E);
    }
}
