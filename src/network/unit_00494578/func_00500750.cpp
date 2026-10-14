/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char head[0x178]; int value178; char pad[0x19C-0x17C]; int value19C; char tail[0x1D4-0x1A0]; };
struct Obj { char pad0[0x40]; int value40; char pad1[0x5A8-0x44]; Block *dst; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *, int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005005C0(void *, void *) throw();
extern "C" int func_00500750(Obj *o, Block *src) {
    int r = func_004F0C88(o);
    if (r) {
        func_005A48D8(o->dst, 0, 0x1D4);
        Block *w = o->dst;
        *w = *src;
        int value = o->value40;
        w->value19C = 2;
        w->value178 = value;
        if (func_005005C0(o, (char *)w + 0x15) == 0) return 1;
        return func_004F0CD0(o, 0x14);
    }
    return r;
}
