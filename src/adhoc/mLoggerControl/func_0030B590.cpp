/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj;
struct Array { s32 x; Obj **data; };
struct Obj { s32 x; char *vt; s32 y; Array *arr; };
struct Handle { Obj *p; s32 pad[3]; };
struct VGet { short delta, index; s32 (*fn)(void *); };
extern "C" void func_0030BB18(void *);
extern "C" void func_00309378(void *, s32) throw();
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_0030B590(Obj *self, Obj **dst, s32 index) {
    Obj *p;
    if (self->arr) {
        VGet *e = (VGet *)(self->vt + 0x50);
        e->fn((char *)self + e->delta);
        Obj **src = self->arr->data + index;
        if (dst != src) {
            p = *src;
            if (p) func_003285A8(p);
            if (*dst) func_003285F8(*dst);
            *dst = p;
        }
    } else {
        Handle h;
        func_0030BB18(&h);
        if (dst != (Obj **)&h) {
            p = h.p;
            if (p) func_003285A8(p);
            if (*dst) func_003285F8(*dst);
            *dst = p;
        }
        func_00309378(&h, 2);
    }
}
