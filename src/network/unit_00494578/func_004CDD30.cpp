/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a, b; unsigned char *data; };
struct Arg { char pad[12]; int a, b; };
struct Obj { int f0; void *dev; char pad8[0x48]; unsigned size; unsigned start; char pad58[12]; int count; char pad68[12]; int zero; void *vtable; int f7c, f80; };
extern char D_006894C8[];
extern "C" Obj *func_004CB618(Obj *, void *, int, Arg *) throw();
extern "C" Buf *func_004CA820(void *, unsigned) throw();
extern "C" void func_004CA938(void *, Buf *) throw();
extern "C" int func_004CDF10(Obj *, unsigned);
extern "C" void func_004CDF98(Obj *, int, int);
extern "C" void func_004CDD30(Obj *o, void *arg1, int arg2, Arg *arg3) {
    func_004CB618(o, arg1, arg2, arg3);
    o->vtable = D_006894C8;
    o->f7c = arg3->a;
    o->f80 = arg3->b;
    int value = func_004CDF10(o, 1);
    if (value > 0) func_004CDF98(o, 1, value & 0xffff7fff);
    int sec = 0;
    o->zero = 0;
    unsigned off = 0;
    int i = 0;
    while (i < o->count) {
        Buf *b = func_004CA820(o->dev, o->start + sec);
        if (!b) {
            i += o->size >> 1;
        } else {
            while (i < o->count && off < o->size) {
                unsigned char *p = b->data + off;
                off += 2;
                if ((p[1] << 8 | p[0]) == 0) ++o->zero;
                ++i;
            }
            func_004CA938(o->dev, b);
        }
        off = 0;
        ++sec;
    }
}
