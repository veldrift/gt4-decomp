/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { int words[39]; };
struct Buffer { Data data; char pad9c[0x104-0x9c]; int f104; int callback; int f10c, f110; };
struct Obj { char pad0[0x44]; int f44; char pad48[0x5a8-0x48]; Buffer *buf; char pad5ac[0xb0c-0x5ac]; Data data; };
extern "C" int func_004F0C88(Obj *) throw();
extern "C" int func_004F0CD0(Obj *, int) throw();
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_004F1978();
extern "C" int func_004F1820(Obj *o) {
    if (func_004F0C88(o)) {
        func_005A48D8(o->buf, 0, 0x114);
        Buffer *p = o->buf;
        p->data = o->data;
        p->f104 = o->f44;
        p->callback = (int)func_004F1978;
        p->f10c = 0;
        p->f110 = 0;
        return func_004F0CD0(o, 4);
    }
}
