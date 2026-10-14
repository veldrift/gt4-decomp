struct Entry { short delta, index; void *fn; };
struct Peer { Entry *vt; };
struct Obj { Entry *vt; char pad[0x9bc-4]; int index; char cam[0x40]; };
extern "C" void func_003FB4C0(void *, int);
extern "C" void func_00373490(Obj *o, float x) {
    Entry *e = o->vt + 27;
    Peer *p = ((Peer *(*)(void *, int))e->fn)((char *)o + e->delta, o->index);
    if (!p) return func_003FB4C0(o->cam, 0);
    if (x == 0.0f) {
        Entry *e = p->vt + 13;
        ((void (*)(void *, void *))e->fn)((char *)p + e->delta, o->cam);
    } else {
        Entry *e = p->vt + 16;
        ((void (*)(void *, void *, float))e->fn)((char *)p + e->delta, o->cam, x);
    }
}
