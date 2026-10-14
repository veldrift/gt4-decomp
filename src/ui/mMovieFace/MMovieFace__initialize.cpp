/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int x; char *vt; };
struct Entry { short delta; short index; void (*fn)(void *, int *, int *); };
extern char D_00618E40[];
extern "C" void func_001FD370(void *, int, int);
extern "C" void func_0022ACC8(void *, int);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void MMovieFace__initialize(void *unused, int count, char *args) {
    void *buf0[4];
    void *buf1[4];
    int x, y;
    if (count >= 2) {
        func_002FC8C8(buf0, args);
        void **p = buf1;
        func_002FC8C8(p, args + 4);
        int a = func_002FE250(buf0[0]);
        int b = func_002FE250(p[0]);
        func_001FD370(D_00618E40, a, b);
        func_002FC870(p, 2);
        func_002FC870(buf0, 2);
    } else if (count == 1) {
        func_0022AD20(buf0, args);
        Obj *o = (Obj *)buf0[0];
        Entry *e = (Entry *)(o->vt + 0x200);
        e->fn((char *)o + e->delta, &x, &y);
        func_001FD370(D_00618E40, x, y);
        func_0022ACC8(buf0, 2);
    }
}
