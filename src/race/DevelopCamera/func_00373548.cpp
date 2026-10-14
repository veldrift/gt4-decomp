struct Entry { short delta, index; void *fn; };
struct Peer { Entry *vt; };
struct Record { Peer *peer; char pad[0x19c-4]; };
struct Obj { Entry *vt; char pad[0x158-4]; Record records[5]; char gap[0x9bc-0x158-5*0x19c]; int index; char tail[0xA84-0x9c0]; };
extern "C" void func_004A7454();
extern "C" void func_004A7698(void *);
extern "C" void func_00373548(Obj *o, float x) {
    Entry *e = o->vt + 27;
    Peer *p = ((Peer *(*)(void *, int))e->fn)((char *)o + e->delta, o->index);
    if (!p) return func_004A7454();
    if (p == o->records[o->index].peer) func_004A7698((char *)o + 0xA40);
    if (x == 0.0f) {
        Entry *e = p->vt + 14;
        ((void (*)(void *))e->fn)((char *)p + e->delta);
    } else {
        Entry *e = p->vt + 17;
        ((void (*)(void *, float))e->fn)((char *)p + e->delta, x);
    }
    func_004A7698((char *)o + 0xA80);
}
