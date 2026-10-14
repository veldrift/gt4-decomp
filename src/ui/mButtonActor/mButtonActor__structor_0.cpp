/* compiler: ee-gcc2.96-no-strict-aliasing */
struct mActorBase {
    int m0;
    virtual ~mActorBase();
};
struct mActor : mActorBase {
    int m8, mC, m10;
    mActor() __asm__("func_001FF130");
};
struct mButtonActor : mActor {
    int m14, m18, m1C;
    float m20, m24, m28, m2C, m30, m34;
    int m38, m3C;
    float m40;
    mButtonActor() __asm__("func_0027E098");
    virtual ~mButtonActor();
};
mButtonActor::mButtonActor()
    : m14(0), m18(0), m1C(0), m38(1), m3C(0), m40(0x1.111110p-5f) {}
