struct Peer;
struct EntryA { short delta, index; Peer *(*fn)(void *, int); };
struct EntryB { short delta, index; float (*fn)(void *); };
struct Peer { EntryB *vt; };
struct Obj { EntryA *vt; char pad[0x9bc-4]; int index; };
extern "C" float DevelopCamera__virtual_34(Obj *o) {
    EntryA *e = o->vt + 27;
    Peer *p = e->fn((char *)o + e->delta, o->index);
    float result = 0.0f;
    if (p) {
        EntryB *e = p->vt + 28;
        result = e->fn((char *)p + e->delta);
    }
    return result;
}
