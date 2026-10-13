typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Holder {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_00309360(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BB18(void *);

extern "C" void *func_002EEF40(void *arg0, void *arg1) {
    s32 buf0[4];
    Holder *h = (Holder *)((char *)arg1 + 0x10);
    if (h->unk4 != h->unk8) {
        func_00309360(buf0, h->unk8 - 4);
        s32 p = h->unk8 - 4;
        h->unk8 = p;
        func_00309378((void *)p, 2);
        func_00309360(arg0, (s32)buf0);
        func_00309378(buf0, 2);
    } else {
        func_0030BB18(arg0);
    }
    return arg0;
}
