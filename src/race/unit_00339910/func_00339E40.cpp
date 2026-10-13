typedef int s32;
typedef unsigned char u8;

struct Obj;

struct Frame {
    s32 obj0[0x6A0 / 4];
    s32 obj1[0x60 / 4];
    s32 res[0x10 / 4];
};

extern char D_0069F2E8[];
extern char D_0069F2E0[];

extern "C" void func_003B08C8(Obj *arg0);
extern "C" void func_003B05A8(Obj *arg0);
extern "C" void func_00339CF8(void *arg0, char *arg1, char *arg2);
extern "C" void func_0033B650(char *arg0, void *arg1, void *arg2);
extern "C" s32 func_0045B368(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_00339E40(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Frame f;

    func_003B08C8((Obj *)&f);
    func_003B05A8((Obj *)f.obj1);
    func_0045B368((s32)f.res, arg1, arg0, (s32)D_0069F2E8);
    if (f.res[1] >= 0) {
        func_00339CF8((void *)arg0, (char *)&f, (char *)f.obj1);
        func_0033B650((char *)arg2, (void *)&f, (void *)f.obj1);
        func_0045B368((s32)f.res, arg1, arg0, (s32)D_0069F2E0);
        if (f.res[1] >= 0) {
            func_00339CF8((void *)arg0, (char *)&f, (char *)f.obj1);
            func_0033B650((char *)arg3, (void *)&f, (void *)f.obj1);
        }
    }
}
