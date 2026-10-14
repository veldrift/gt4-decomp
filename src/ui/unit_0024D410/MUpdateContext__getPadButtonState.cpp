/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct RefCounter;
struct E { short delta, index; void *(*fn)(void *); };
struct E2 { short delta, index; void *(*fn)(void *, void *); };
struct O { int pad; char *vt; };
extern "C" void func_0024E3D0(void *, void *) throw();
extern "C" void func_0024E378(void *, int) throw();
extern "C" void func_002FE278(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);
extern "C" void MUpdateContext__getPadButtonState(s32 *out, void *in, int n, O **other) {
    s32 b0[4];
    s32 b1[4];
    if (n == 1) {
        func_0024E3D0(b0, in);
        O *o = *other;
        char *self = (char *)b0[0];
        E *e = (E *)(o->vt + 0x58);
        E2 *e2 = (E2 *)(((O *)self)->vt + 0x1d8);
        self = self + e2->delta;
        void *r = e->fn((char *)o + e->delta);
        r = e2->fn(self, r);
        s32 *p = b1;
        func_002FE278(p, r);
        if (out != p) {
            s32 v = *p;
            if (v) func_003285A8((RefCounter *)v);
            s32 old = *out;
            if (old) func_003285F8((RefCounter *)old);
            *out = v;
        }
        func_002FC870(p, 2);
        func_0024E378(b0, 2);
    }
}
