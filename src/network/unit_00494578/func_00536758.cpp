struct Obj { char pad[0x158]; int state; };
struct Req { Obj *obj; unsigned id; int data; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern void (*D_0064B4D0)(Req *);
extern int D_0064B4D4;
extern "C" void func_00536758(unsigned short id, Obj *obj) {
    if (obj && obj->state == 2 && D_0064B4D0) {
        Req r;
        func_005A48D8(&r, 0, 12);
        r.obj = obj;
        r.id = id;
        r.data = D_0064B4D4;
        D_0064B4D0(&r);
    }
}
