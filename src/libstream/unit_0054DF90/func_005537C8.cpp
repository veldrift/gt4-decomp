/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x5C]; void *f5C; void *f60; char pad64[0xDC-0x64]; int fDC; int *fE0; };
struct Callback { void (*fn)(Obj *); Obj *self; };
struct Buffer { void *data; int size; };
extern char D_008700C0[];
extern char D_008710C0[];
extern char D_0064CCC0[];
extern "C" void func_00553B80(Obj *);
extern "C" void func_00553C08(Obj *);
extern "C" int func_00578B50(unsigned int, int);
extern "C" void *func_00578610(int);
extern "C" void *func_00578968(Callback *, Buffer *, void *);
extern "C" void func_005788B8(void *);
extern "C" void func_00554180(void *);
extern "C" void func_005537C8(Obj *o) {
    Callback cb;
    Buffer b2;
    Buffer b1;
    int unused[4];
    o->fDC = 0;
    o->fE0 = &o->fDC;
    Buffer *buf1 = &b1;
    cb.fn = func_00553B80;
    cb.self = o;
    buf1->data = D_008700C0;
    buf1->size = 0x1000;
    o->f60 = func_00578968(&cb, buf1, func_00578610(func_00578B50(3, -1)));
    func_005788B8(o->f60);
    Buffer *buf2 = &b2;
    cb.fn = func_00553C08;
    cb.self = o;
    buf2->data = D_008710C0;
    buf2->size = 0x1000;
    o->f5C = func_00578968(&cb, buf2, func_00578610(func_00578B50(3, 1)));
    func_005788B8(o->f5C);
    func_00554180(D_0064CCC0);
}
