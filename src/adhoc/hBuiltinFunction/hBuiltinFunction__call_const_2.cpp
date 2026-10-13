typedef int s32;

struct RefCounter;

struct func_0032CFA8_self {
    char pad0[0xC];
    void (*fn)(void *, s32, s32);
};

struct func_0032CFA8_sub {
    char pad0[0x14];
    s32 *arr;
    char pad1[0x8];
    s32 cnt;
};

struct func_0032CFA8_owner {
    char pad0[0x2C];
    struct func_0032CFA8_sub *sub;
};

extern "C" void func_0030BB18(void *a0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_0032CFA8(void *arg0, void **arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    struct func_0032CFA8_sub *sub;
    s32 *slot;

    func_0030BB18(buf0);
    ((struct func_0032CFA8_self *)arg0)->fn(buf0, arg2, arg3);
    sub = ((struct func_0032CFA8_owner *)*arg1)->sub;
    slot = sub->arr + sub->cnt;
    if (slot != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *slot;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *slot = newVal;
    }
    sub->cnt = sub->cnt + 1;
    func_00309378(buf0, 2);
}
