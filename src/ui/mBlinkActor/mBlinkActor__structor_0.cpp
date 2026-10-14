/* compiler: ee-gcc2.96-no-strict-aliasing */
struct mActorBase {
    int m0;
    virtual ~mActorBase();
};
struct mActor : mActorBase {
    int m8, mC, m10;
    mActor() __asm__("func_001FF130");
};
struct mBlinkActor : mActor {
    int m14, m18, m1C, m20, m24, m28, m2C;
    float m30, m34;
    int m38, m3C;
    mBlinkActor() __asm__("func_00278E98");
    virtual ~mBlinkActor();
};
mBlinkActor::mBlinkActor()
    : m14(0), m18(0), m20(0), m24(1), m28(0), m2C(0),
      m30(0x1.111110p-5f), m34(1.0f), m38(0), m3C(0) {}
