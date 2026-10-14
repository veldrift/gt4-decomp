typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_00137D60(void *arg0, int arg1);
extern "C" void func_00137DB8(void *arg0, void *arg1);
extern "C" void func_0013A9A8(void *arg0, int arg1);

extern "C" void MCarFace__setColorIndex(s32 arg0, void *arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    ObjA *obj;
    VEntry *entry;
    s32 result;

    obj = arg3->obj;
    entry = obj->vtbl + 11;
    result = entry->fn((char *)obj + entry->delta);
    func_00137DB8(buf, arg1);
    func_0013A9A8((void *)buf[0], result);
    func_00137D60(buf, 2);
}
