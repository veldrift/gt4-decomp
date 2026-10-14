/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Self {
    char pad[0x14];
    s32 f14;
    s32 f18;
};

extern "C" s32 func_003EBEB0(void *o, void *pad, unsigned int mask, int c) throw();
extern "C" s32 func_004269A0(void *pad, s32 mask);
extern "C" s32 func_004269D0(void *pad, s32 mask);
extern "C" int func_00476500(void *item);
extern "C" s32 func_00476558(void *item);

extern "C" s32 func_003EBF40(Self *self, void *item, void *pad) {
    s32 res = 0;
    if (item != 0) {
        s32 a = func_004269A0(pad, 0x10);
        s32 b = func_004269A0(pad, 0x20);
        self->f18 = !a && b;
        self->f14 = a;
        res = (a != 0) | (b != 0);
        if (a != 0) {
            func_00476500(item);
        } else if (func_004269D0(pad, 0x10) != 0) {
            func_00476558(item);
        }
        res |= (func_003EBEB0(item, pad, 1, 0x26) != 0);
        res = (res != 0) | (func_003EBEB0(item, pad, 2, 0x28) != 0);
        res |= (func_003EBEB0(item, pad, 8, 0x27) != 0);
        res |= (func_003EBEB0(item, pad, 4, 0x25) != 0);
        res |= (func_003EBEB0(item, pad, 0x10, 0x20) != 0);
        res |= (func_003EBEB0(item, pad, 0x20, 0x1B) != 0);
    }
    return res;
}
