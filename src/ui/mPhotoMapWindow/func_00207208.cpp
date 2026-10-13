typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
};

struct Obj {
    s32 m0;
    VEntry *vtbl;
};

extern "C" u64 func_00266088(Obj *arg0);
extern "C" void func_00266100(Obj *arg0, s32 arg1);
extern "C" u64 func_00266128(Obj *arg0);
extern "C" void func_002661A0(Obj *arg0, s32 arg1);

extern "C" void func_00207208(Obj *arg0, s32 arg1, Obj *arg2) {
    VEntry *entry;

    entry = arg2->vtbl + 92;
    entry->fn((char *)arg2 + entry->delta);
    if (func_00266088(arg2) != 0) {
        func_00266100(arg0, 1);
    }
    if (func_00266128(arg2) != 0) {
        func_002661A0(arg0, 1);
    }
}
