typedef int s32;

extern "C" void ScrollBarUnit__inc(void *arg0, float fparg0);
extern "C" void mWidget__setWindowX(void *c, float y);

struct Obj002D2D58 {
    char pad0[0xC0];
    void *unkC0;
};

struct Sub002D2D58 {
    char pad0[0x14];
    float unk14;
};

extern "C" s32 mScrollWindow__onVDecButtonPress(char *arg0) {
    s32 var_v0 = 0;
    char *temp_s1 = arg0 + 0xC4;
    if (((struct Obj002D2D58 *)arg0)->unkC0 == 0) {
        return var_v0;
    }
    ScrollBarUnit__inc(temp_s1, 8.0f);
    mWidget__setWindowX(((struct Obj002D2D58 *)arg0)->unkC0, -((struct Sub002D2D58 *)temp_s1)->unk14);
    return 1;
}
