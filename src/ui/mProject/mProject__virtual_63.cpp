/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S;
struct VEntry { short delta; short index; void (*fn)(void *, S *); };
struct S { int pad0; VEntry *vt; };

extern "C" int func_00206868(S *);
extern "C" int func_0025C300(S *);
extern "C" void mSceneViewFace__virtual_63(void);
extern "C" void func_00229DC8(S *) throw();

extern "C" void mProject__virtual_63(S *self) {
    mSceneViewFace__virtual_63();
    S *p = (S *)func_00206868(self);
    if (p != 0) {
        do {
            VEntry *e = &self->vt[95];
            e->fn((char *)self + e->delta, p);
            p = (S *)func_0025C300(p);
        } while (p != 0);
    }
    func_00229DC8(self);
}
