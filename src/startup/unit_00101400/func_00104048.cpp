/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V4 {
    float x, y, z, w;
    V4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
struct Base {
    Base() __asm__("func_0010AA08");
    virtual ~Base();
};
struct Self : Base {
    int f4, f8;
    V4 a, b;
    Self() __asm__("func_00104048");
    virtual ~Self();
};
Self::Self() : f4(1), f8(0), a(0.5098039f, 0.5098039f, 0.58823526f, 1.0f), b(0.9f, 0.0f, 0.0f, 1.0f) {}
