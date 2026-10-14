/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Root { int f0; virtual ~Root(); };
struct mColorFace : Root {
    virtual ~mColorFace();
    char pad[0xB0];
    mColorFace() __asm__("func_00286360");
};
struct Inner { int x; Inner() {} };
struct Blank { Inner i; int y; };
struct mGraphFace : mColorFace {
    int fB8;
    float fBC;
    int fC0;
    Blank data[256];
    mGraphFace() __asm__("func_0029E9D0");
    virtual ~mGraphFace();
};
mGraphFace::mGraphFace() : fB8(1), fBC(2.0f) {
    fC0 = 0;
}
