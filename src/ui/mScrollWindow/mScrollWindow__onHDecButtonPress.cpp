/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void ScrollBarUnit__inc(void *, float) throw();
extern "C" void mWidget__setWindowX(void *, float);
struct Obj { char pad[0xC0]; void *child; };
struct Sub { char pad[0x14]; float position; };
extern "C" int mScrollWindow__onHDecButtonPress(char *self) {
    int result = 0;
    char *bar = self + 0xC4;
    if (((Obj *)self)->child == 0) return result;
    ScrollBarUnit__inc(bar, -8.0f);
    mWidget__setWindowX(((Obj *)self)->child, -((Sub *)bar)->position);
    return 1;
}
