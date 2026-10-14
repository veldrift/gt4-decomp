/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct mSelectBox {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[0x38];
    f32 unkEC;
};
extern "C" s32 func_00206868(void *);
extern "C" f32 mWidget__getWindowW(void *);
extern "C" f32 mWidget__getWindowH(void *);
extern "C" void mWidget__setWindowPosition(void *, f32, f32);
extern "C" void *func_0025C300(void *);
extern "C" void mWidget__virtual_70(mSelectBox *, void *, s32);
extern "C" s32 func_00265DC8(mSelectBox *);
extern "C" f32 func_002D4970(mSelectBox *);
extern "C" f32 func_002D4980(mSelectBox *);

extern "C" void mSelectBox__virtual_70(mSelectBox *self, void *arg1, s32 flag) {
    mWidget__virtual_70(self, arg1, 0);
    if (flag != 0) {
        if (func_00265DC8(self) != 0) {
            f32 a = func_002D4970(self);
            f32 y = self->unkEC;
            void *w;
            if (self->unkB0 == 0) {
                f32 h = mWidget__getWindowH(self);
                w = (void *)func_00206868(self);
                if (w != 0) {
                    do {
                        mWidget__setWindowPosition(w, y, (h - mWidget__getWindowH(w)) - a);
                        y += func_002D4980(self);
                        y += mWidget__getWindowW(w);
                        w = func_0025C300(w);
                    } while (w != 0);
                }
            } else {
                w = (void *)func_00206868(self);
                if (w != 0) {
                    do {
                        mWidget__setWindowPosition(w, a, y);
                        y += func_002D4980(self);
                        y += mWidget__getWindowH(w);
                        w = func_0025C300(w);
                    } while (w != 0);
                }
            }
        }
    }
}
