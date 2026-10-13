typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct mCancelEvent {
    char pad0[4];
    VEntry *vtbl;
    char pad8[8];
    s32 unk10;
    s32 unk14;
};

static inline s32 vcall_50(char *o) {
    VEntry *e = (VEntry *)((char *)((mCancelEvent *)o)->vtbl + 0x50);
    return e->fn(o + e->delta);
}

extern char D_0069AB28[];
extern char D_0069AB30[];
extern char D_0069AB48[];

extern "C" void func_005D4AD8(const char *fmt, ...);
extern "C" s32 func_00305570(s32 arg0);
extern "C" s32 func_0028EA08(void *arg0);
extern "C" s32 func_0028EA18(void *arg0);
extern "C" s32 func_0028E858(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00282DF8(void *arg0) {
    mCancelEvent *self = (mCancelEvent *)arg0;
    s32 s1;
    s32 r;

    func_005D4AD8(D_0069AB28);
    func_005D4AD8(D_0069AB30,
                  func_00305570(vcall_50((char *)self)),
                  self->unk14,
                  self->unk10);
    s1 = func_0028EA08(self);
    r = func_0028E858(self, s1, func_0028EA18(self));
    func_005D4AD8(D_0069AB48);
    return r;
}
