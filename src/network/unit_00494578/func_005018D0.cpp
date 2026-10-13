typedef int s32;

struct List;
struct Node;
struct Obj00500EB0;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern "C" void func_0057CB00(List *arg0, Node *arg1);
extern "C" s32 func_0057CC80(s32 arg0, void *arg1);
extern "C" void func_00500EB0(Obj00500EB0 *arg0);

extern "C" void func_005018D0(void *arg0, void *arg1) {
    s32 sp[4];
    char *self = (char *)arg0;
    char *obj = (char *)arg1;

    sp[0] = (s32)(self + 8);
    func_00576788(sp[0]);
    if (func_0057CC80((s32)(self + 0x1D8), arg1) == 0 &&
        func_0057CC80((s32)(self + 0x1E4), arg1) == 0) {
        func_0057CC80((s32)(self + 0x1F0), arg1);
    }
    if (*(s32 *)(obj + 0x44) == 0) {
        func_0057CB00((List *)(self + 0x1CC), (Node *)arg1);
    }
    {
        char *p = *(char **)(obj + 0x48);
        VEntry *e = (VEntry *)(p + 0x18);
        e->fn(obj + e->delta);
    }
    func_00500EB0((Obj00500EB0 *)arg1);
    func_005767C0(sp[0]);
}
