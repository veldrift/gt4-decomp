/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned long long u64;
struct Obj {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[8];
    s32 unkBC;
    char padC0[0x2C];
    f32 unkEC;
};
extern "C" s32 func_00206868(void *);
extern "C" f32 mWidget__getWindowW(void *);
extern "C" f32 mWidget__getWindowH(void *);
extern "C" void mWidget__setWindowPosition(void *, f32, f32);
extern "C" void *func_0025C300(void *);
extern "C" void mWidget__virtual_70(Obj *, void *, s32);
extern "C" s32 func_00265DC8(Obj *);
extern "C" void mWidget__setActive(void *, s32);
extern "C" u64 func_00266088(Obj *);
extern "C" f32 func_002D4970(Obj *);
extern "C" f32 func_002D4980(Obj *);

extern "C" void mSelectBar__virtual_70(Obj *self, void *arg1, s32 flag) {
    mWidget__virtual_70(self, arg1, 0);
    if (flag != 0) {
        if (func_00265DC8(self) != 0) {
            f32 a = func_002D4970(self);
            f32 y = self->unkEC;
            s32 i;
            void *w;
            if (self->unkB0 == 0) {
                i = 0;
                f32 h = mWidget__getWindowH(self);
                w = (void *)func_00206868(self);
                if (w != 0) {
                    do {
                        mWidget__setWindowPosition(w, y, (h - mWidget__getWindowH(w)) - a);
                        y += func_002D4980(self);
                        y += mWidget__getWindowW(w);
                        if (func_00266088(self) != 0 && i == self->unkBC) mWidget__setActive(w, 1);
                        else mWidget__setActive(w, 0);
                        i++;
                        w = func_0025C300(w);
                    } while (w != 0);
                }
            } else {
                i = 0;
                w = (void *)func_00206868(self);
                if (w != 0) {
                    do {
                        mWidget__setWindowPosition(w, a, y);
                        y += func_002D4980(self);
                        y += mWidget__getWindowH(w);
                        if (func_00266088(self) != 0 && i == self->unkBC) mWidget__setActive(w, 1);
                        else mWidget__setActive(w, 0);
                        i++;
                        w = func_0025C300(w);
                    } while (w != 0);
                }
            }
        }
    }
}
