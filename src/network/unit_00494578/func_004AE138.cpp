/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void *fn; };
struct Pair { int a,b; };
struct Obj { char pad0[0x44]; Entry *vt; char pad48[0x3084-0x48]; Pair pair[2]; int index; };
extern "C" void func_00572D88(void *,int,int);
extern "C" void func_004AE138(Obj *o) {
    Entry *e = o->vt + 7;
    ((void (*)(void *,int))e->fn)((char*)o + e->delta,0);
    Pair *q = &o->pair[o->index];
    func_00572D88(o,q->a,q->b);
    o->index ^= 1;
    Entry *f = o->vt + 6;
    ((void (*)(void *))f->fn)((char*)o + f->delta);
}
