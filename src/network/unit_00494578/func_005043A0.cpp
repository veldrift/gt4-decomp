typedef int s32;

struct Obj {
    char pad[4];
    char *rec;
};

extern "C" void func_00576100(Obj *arg0);
extern "C" void func_00576140(Obj *arg0);

extern "C" void func_005043A0(Obj *arg0) {
    s32 sp[4];
    char *v0 = arg0->rec;
    if (v0 != 0) {
        volatile s32 *p = (volatile s32 *)(v0 + 0x1C);
        sp[0] = (s32)(v0 + 0x38);
        func_00576100((Obj *)sp[0]);
        p[0] = 0;
        p[2] = 0;
        p[1] = 0;
        func_00576140((Obj *)sp[0]);
    }
}
