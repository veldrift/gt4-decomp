/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char pad[0xA4]; s32 fA4; s32 fA8; s32 fAC; };
extern "C" void func_001AAEA0(void *);
extern "C" void func_001AAF80(void *);
extern "C" void mUpdateContext__Sync(int);
extern "C" void func_001AAA40(Obj *self) {
    s32 a;
    a = self->fA4;
    if (a == 0) {
        do {
            switch (self->fAC) {
            case 0:
                mUpdateContext__Sync(1);
                a = self->fA4;
                break;
            case 1:
                mUpdateContext__Sync(1);
                a = self->fA4;
                break;
            case 2:
                func_001AAF80(self);
                func_001AAEA0(self);
                self->fAC = 1;
                a = self->fA4;
                break;
            case 3:
                self->fA4 = 1;
                a = 1;
                break;
            }
        } while (a == 0);
    }
}
