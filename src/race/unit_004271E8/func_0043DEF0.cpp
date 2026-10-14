struct Blk { int w[0x11A]; };
struct A32 { int w[8]; };
struct P8 { int w[2]; };
struct B4 { char b[4]; };
struct B12 { char b[12]; };
struct Body { Blk a; A32 b; B4 c; B12 d; A32 f; };
struct VEntry { short delta; short index; int (*fn)(void *, void *); };
struct C { VEntry *vtbl; int pad; Body body; };
extern "C" int func_0043DEF0(C *self, Body *src) {
    self->body.a = src->a;
    self->body.b = src->b;
    self->body.c = src->c;
    self->body.d = src->d;
    self->body.f = src->f;
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, src);
}
