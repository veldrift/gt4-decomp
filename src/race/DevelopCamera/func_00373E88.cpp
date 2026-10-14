struct Peer;
struct EntryA { short delta, index; Peer *(*fn)(void *, int); };
struct EntryB { short delta, index; int (*fn)(void *, void *, int); };
struct Peer { EntryB *vt; };
struct Obj { EntryA *vt; char pad[0x9bc-4]; int index; char cam[0x40]; };
extern "C" void func_00373E88(Obj *o, int unused, int value) {
    EntryA *e = o->vt + 27;
    Peer *p = e->fn((char *)o + e->delta, o->index);
    if (p) {
        EntryB *e = p->vt + 30;
        e->fn((char *)p + e->delta, o->cam, value);
    }
}
