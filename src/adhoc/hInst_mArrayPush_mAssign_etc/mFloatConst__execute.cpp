typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct func_0031B688_arg0 {
    char pad0[0x8];
    f32 unk8;
};

struct func_0031B688_sub {
    char pad0[0x14];
    s32 *arr;
    char pad1[0x8];
    s32 cnt;
};

struct func_0031B688_arg1 {
    char pad0[0x2C];
    struct func_0031B688_sub *sub;
};

extern "C" void func_002F7B68(void *arg0, s32 arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_0031B688(void *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    struct func_0031B688_sub *sub;
    s32 *slot;

    func_002F9360(buf0, ((struct func_0031B688_arg0 *)arg0)->unk8);
    sub = ((struct func_0031B688_arg1 *)arg1)->sub;
    slot = sub->arr + sub->cnt;
    if (slot != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *slot;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *slot = newVal;
    }
    sub->cnt = sub->cnt + 1;
    func_002F7B68(buf0, 2);
}
