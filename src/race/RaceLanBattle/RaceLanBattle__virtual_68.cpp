/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta, index; int (*fn)(void *); };
struct Sub { char pad[0xf4]; int state; };
struct Obj { char p[0x64]; V *vt; char q[0xe480-0x68]; Sub *sub; };
extern "C" int RaceLanBattle__virtual_68(Obj *self) {
    if (self->sub->state < 0) {
        V *e = self->vt + 0x230/8;
        return e->fn((char *)self + e->delta);
    }
    int result = (int)self + 0xf184;
    return result;
}
