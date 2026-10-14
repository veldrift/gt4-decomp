/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct CB { void (*fn)(void *); void *self; };
struct Obj {
    char pad0[0xA0];
    s32 fA0, fA4, fA8, fAC;
    s32 bufs[2];
    s32 fB8;
};
extern "C" void mTextFace__virtual_67(void *);
extern "C" void func_001AAF80(void *);
extern "C" s32 func_00575098(void *, int);
extern "C" void func_005788B8(s32);
extern "C" s32 malloc(s32) throw();
extern "C" void func_001C6E00(void *, void *, s32, s32);
extern "C" void func_001C7298(void *);
extern "C" void func_001AAA20(void *);
extern "C" void mSlideShowFace__virtual_67(Obj *self) {
    mTextFace__virtual_67(self);
    self->fA8 = 0;
    self->fAC = 1;
    self->fA4 = 0;
    func_001AAF80(self);
    CB cb;
    cb.fn = func_001AAA20;
    cb.self = self;
    s32 r = func_00575098(&cb, 0);
    self->fA0 = r;
    func_005788B8(r);
    for (s32 k = 0; k < 2; k++) {
        self->bufs[k] = malloc(0x384000);
    }
    s32 m = malloc(0x80000);
    self->fB8 = m;
    func_001C6E00((char *)self + 0xBC, self->bufs, m, 0x80000);
    func_001C7298((char *)self + 0x1E9C);
}
