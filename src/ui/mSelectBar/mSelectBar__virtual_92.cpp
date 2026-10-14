/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Obj {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[8];
    s32 unkBC;
    char padC0[0x24];
    f32 unkE4;
    f32 unkE8;
};
extern "C" s32 func_00206868(void *);
extern "C" void func_00207378(void *, void *, void *);
extern "C" void func_00231C10(void *);
extern "C" void func_00231C48(void *);
extern "C" f32 mWidget__getWindowW(void *);
extern "C" f32 mWidget__getWindowH(void *);
extern "C" void *func_0025C300(void *);
extern "C" void mSceneViewFace__virtual_92(Obj *, void *);
extern "C" s32 func_00265DC8(Obj *);
extern "C" f32 func_002D4980(Obj *);

extern "C" void mSelectBar__virtual_92(Obj *self, void *arg1) {
    mSceneViewFace__virtual_92(self, arg1);
    if (func_00265DC8(self) != 0) {
        f32 e;
        f32 sz;
        if (self->unkB0 == 0) e = self->unkE4; else e = self->unkE8;
        if (self->unkB0 == 0) sz = mWidget__getWindowW(self); else sz = mWidget__getWindowH(self);
        s32 *pBC = &self->unkBC;
        s32 i = 0;
        void *sel = 0;
        s32 n = (s32)(sz / (e + func_002D4980(self)));
        s32 lo = *pBC - n;
        s32 hi = *pBC + n;
        func_00231C10(arg1);
        void *w = (void *)func_00206868(self);
        if (w != 0) {
            do {
                if (i >= lo && i <= hi) {
                    if (i != *pBC) func_00207378(self, arg1, w);
                    else sel = w;
                }
                i++;
                w = func_0025C300(w);
            } while (w != 0);
        }
        if (sel != 0) func_00207378(self, arg1, sel);
        func_00231C48(arg1);
    }
}
