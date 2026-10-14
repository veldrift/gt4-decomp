struct Blk { int w[0x11A]; };
struct A32 { int w[8]; };
struct B4 { char b[4]; };
struct B12 { char b[12]; };
struct Body { Blk a; A32 b; B4 c; B12 d; A32 f; };
struct VEntry { short delta; short index; int (*fn)(void *, void *); };
struct C { VEntry *vtbl; int pad; Body body; };
extern "C" int func_0043E098(C *self, Body *dst) {
    dst->a = self->body.a;
    dst->b = self->body.b;
    dst->c = self->body.c;
    dst->d = self->body.d;
    dst->f = self->body.f;
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, dst);
}
