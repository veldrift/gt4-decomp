/* A real constructor: the member initialisers in declaration (offset) order are what the
   scheduler turns into the original's store order; hand-written stores cannot. */
struct mActorBase {
    int unk0;
    virtual ~mActorBase();
};

struct mActor : mActorBase {
    int pad8[3];
    mActor() __asm__("func_001FF130");
};

struct mRotateActor : mActor {
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;
    float unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    mRotateActor() __asm__("func_002CCAA8");
    virtual ~mRotateActor();
};

mRotateActor::mRotateActor()
    : unk14(0), unk18(0), unk1C(0), unk20(0), unk24(360.0f), unk28(0x1.999998p-3f),
      unk2C(0), unk30(1), unk34(0), unk38(0), unk3C(1) {
}
