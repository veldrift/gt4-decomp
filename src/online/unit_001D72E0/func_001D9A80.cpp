typedef int s32;

struct S {
    char pad[0x10C];
    s32 flag;
};

extern "C" s32 func_001D9AC8(struct S *s);
extern "C" void mUpdateContext__Sync(s32 arg);

extern "C" s32 func_001D9A80(struct S *self) {
    while (!func_001D9AC8(self)) {
        mUpdateContext__Sync(1);
    }
    return self->flag ^ 1;
}
