typedef int s32;

struct Sub002D2E40 {
    char pad0[0x14];
    float y;
};

struct Self002D2E40 {
    char pad0[0xC0];
    void *c;
};

extern "C" void ScrollBarUnit__inc(struct Sub002D2E40 *arg0, float fparg0);
extern "C" void mWidget__setWindowY(void *c, float y);

extern "C" s32 mScrollWindow__onVIncButtonPress(char *arg0) {
    struct Self002D2E40 *self = (struct Self002D2E40 *)arg0;
    if (self->c == 0)
        return 0;
    struct Sub002D2E40 *s = (struct Sub002D2E40 *)(arg0 + 0xFC);
    ScrollBarUnit__inc(s, -8.0f);
    mWidget__setWindowY(self->c, -s->y);
    return 1;
}
