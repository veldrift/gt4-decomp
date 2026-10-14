/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { s32 x; char *vt; };
struct Handle { Obj *p; s32 pad[3]; };
struct VGet { short delta, index; void *(*fn)(void *); };
struct VCall { short delta, index; void (*fn)(void *, void *, Handle *); };
extern "C" void func_00323D08(void *);
extern "C" void func_002F3478(void *, void *, void *);
extern "C" void func_00309348(void *, void *) throw();
extern "C" void func_00309378(void *, s32) throw();
extern "C" void func_00323B60(void *, s32);
extern "C" void func_0030B410(Obj *self, void *arg1, void *arg2) {
    Handle h;
    Handle t;
    Obj *s;
    func_00323D08(&h);
    VGet *g = (VGet *)(self->vt + 0x50);
    func_002F3478(g->fn((char *)self + g->delta), &h, arg2);
    Handle *pt = &t;
    if (h.p) {
        s = self;
        func_00309348(pt, &s);
        VCall *e = (VCall *)(h.p->vt + 0x48);
        e->fn((char *)h.p + e->delta, arg1, pt);
        func_00309378(pt, 2);
    }
    func_00323B60(&h, 2);
}
