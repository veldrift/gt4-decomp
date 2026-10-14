/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V4 {
    float x, y, z, w;
    V4 &operator=(const V4 &o) {
        if (this != &o) { x = o.x; y = o.y; z = o.z; w = o.w; }
        return *this;
    }
};
struct M {
    char pad[0x18];
    V4 a;
    V4 b;
    float f38;
    V4 c;
    float f4C;
    int f50;
    int f54;
};
extern "C" void mMoveActor__rewind(M *m) {
    if (m->f54 == 0) {
        m->c = m->b;
        m->f4C = m->f38;
    } else {
        m->c = m->a;
        m->f4C = 1.0f;
    }
}
