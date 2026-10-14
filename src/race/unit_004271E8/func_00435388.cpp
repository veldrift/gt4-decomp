/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Word { int value; Word(int v) : value(v) {} Word(const Word &w) : value(w.value) {} };
struct Blob { Word first; int pad; long d[0x97]; };
struct Ent { long a; long flags; long c; long d; };
struct O { char pad[0x7D08]; Blob b; int idx; };
extern "C" void func_00435690(O *, int);
extern "C" void func_00435388(O *self, int idx, const Blob *src) {
    Word saved(self->b.first.value);
    self->b = *src;
    self->idx = idx;
    self->b.first = saved;
    Ent *e = (Ent *)((char *)self + (idx << 5) + 8);
    e->flags |= 2;
    func_00435690(self, idx);
}
