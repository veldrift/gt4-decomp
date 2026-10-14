/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { s32 x; char *vt; };
struct Handle { Obj *p; s32 pad[3]; };
struct VEntry { short delta; short index; void (*fn)(void *, s32, s32, s32); };
extern "C" void func_00309378(void *, s32) throw();
extern "C" void func_0030BB18(void *);
extern "C" void func_0030B410(void *, void *, s32);
extern "C" void hObject__send(void *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handle h;
    func_0030BB18(&h);
    func_0030B410(self, &h, arg2);
    if (h.p) {
        VEntry *e = (VEntry *)(h.p->vt + 0xA8);
        e->fn((char *)h.p + e->delta, arg1, arg3, arg4);
    }
    func_00309378(&h, 2);
}
