/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int size_t;
inline void *operator new(size_t, void *p) { return p; }
struct V4 { float x, y, z, w; V4() { x = 0; y = 0; z = 0; w = 0; } };
struct M {
    int f0;
    char *vt;
    char pad8[0xC];
    int f14;
    V4 a;
    V4 b;
    float f38;
    V4 c;
    float f4C, f50;
    int f54, f58, f5C, f60;
};
extern "C" void mActor__structor_0(void *);
extern char mMoveActor__vtable[];
extern "C" void mMoveActor__structor_0(M *m) {
    mActor__structor_0(m);
    m->vt = mMoveActor__vtable;
    m->f14 = 0;
    new (&m->a) V4;
    new (&m->b) V4;
    m->f38 = 1.0f;
    new (&m->c) V4;
    m->f60 = 1;
    m->f4C = 1.0f;
    m->f50 = 0.3f;
    m->f58 = 0;
    m->f5C = 0;
    m->f54 = 0;
}
