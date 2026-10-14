/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Range {
    s32 cur;
    s32 a;
    s32 b;
    s32 flag;
};
struct mSelectBox {
    char pad0[0xBC];
    Range range;
    char padCC[0x10];
    f32 unkDC_pad;
};
struct Box {
    char pad0[0xBC];
    Range range;
    char padCC[0x10];
    s32 unkDC;
    char padE0[4];
    f32 unkE4;
    f32 unkE8;
    f32 unkEC;
};
extern "C" s32 func_00206868(void *);
extern "C" s32 func_00206880(void *);
extern "C" void mWidget__setWindowW(void *, f32);
extern "C" void mWidget__setWindowH(void *, f32);
extern "C" void *func_0025C300(void *);
extern "C" void func_00265F10(void *, s32);
extern "C" f32 func_002DA2B0(Box *) throw();
extern "C" void func_0057CD90(Range *, s32, s32);

extern "C" void func_002DA5D0(Box *self) {
    Range *r = &self->range;
    func_0057CD90(r, 0, func_00206880(self));
    if (self->unkDC != 0) r->flag = 1;
    else r->flag = 0;
    if (func_00206868(self) != 0) self->unkEC = func_002DA2B0(self);
    s32 i = 0;
    void *w = (void *)func_00206868(self);
    if (w != 0) {
        do {
            f32 a = self->unkE4;
            f32 b = self->unkE8;
            if (i == r->cur) {
                f32 k = *(f32 *)((char *)self + 0xD4);
                a *= k;
                b *= k;
                func_00265F10(w, 1);
            } else {
                func_00265F10(w, 0);
            }
            mWidget__setWindowW(w, a);
            mWidget__setWindowH(w, b);
            i++;
            w = func_0025C300(w);
        } while (w != 0);
    }
}
