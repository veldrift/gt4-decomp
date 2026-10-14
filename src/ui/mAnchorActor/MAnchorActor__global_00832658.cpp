/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int pad; char *vt; };
struct Entry { short delta, index; int (*fn)(void *); };
struct Args { int x,y; Obj *z,*w; };
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_00278118(void *, int) throw();
extern "C" void func_00278170(void *, void *) throw();
extern "C" void func_00278630(int, int, int, int, int);
static inline int vcall(Obj *o) {
    Entry *e = (Entry *)(o->vt + 0x58);
    return e->fn((char *)o + e->delta);
}
extern "C" void MAnchorActor__global_00832658(void *unused, void *src, int n, Args *args) {
    int buf[4];
    if (n >= 4) {
        func_00255110(buf, args);
        int x = buf[0];
        func_002550B8(buf, 2);
        func_00255110(buf, (char *)args + 4);
        int y = buf[0];
        func_002550B8(buf, 2);
        int z = vcall(args->z) != 0;
        int w = vcall(args->w) != 0;
        func_00278170(buf, src);
        func_00278630(buf[0], x, y, z, w);
        func_00278118(buf, 2);
    }
}
