/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Target { char pad[0x40]; unsigned int w; };
struct VEntry { short delta, index; Target *(*fn)(void *, int); };
union Word { unsigned int word; struct { unsigned int lo:16, mid:8, hi:8; } bits; };
struct Self { char *vt; int value; };
extern "C" void RaceSplitDisplayBase__hideAll(Self *self, int value) {
    VEntry *e = (VEntry *)(self->vt + 0xC8);
    Target *t = e->fn((char *)self + e->delta, self->value);
    Word w;
    w.word = t->w;
    w.bits.mid = value;
    t->w = w.word;
}
