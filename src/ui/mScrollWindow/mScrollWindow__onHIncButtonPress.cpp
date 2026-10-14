typedef int s32;

extern "C" void ScrollBarUnit__inc(char *arg0, float fparg0);
extern "C" void mWidget__setWindowY(void *c, float y);

extern "C" s32 mScrollWindow__onHIncButtonPress(char *arg0) {
    s32 var_v0 = 0;
    char *temp_s1 = arg0 + 0xFC;
    if (*(void **)(arg0 + 0xC0) == 0) {
        return var_v0;
    }
    ScrollBarUnit__inc(temp_s1, 8.0f);
    float y = -*(float *)(temp_s1 + 0x14);
    mWidget__setWindowY(*(void **)(arg0 + 0xC0), y);
    var_v0 = 1;
    return var_v0;
}
