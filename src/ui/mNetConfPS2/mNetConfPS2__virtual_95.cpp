typedef int s32;

struct Netcnf;

extern char D_0069A578[];
extern "C" s32 func_004EE048(Netcnf *n, s32 mode, const char *name, s32 arg);

extern "C" void mNetConfPS2__virtual_95(void *arg0, void **arg1, void **arg2, void **arg3) {
    void *obj1 = *arg1;
    s32 off1 = *(s32 *)((char *)obj1 - 0x10);
    void *a1v;
    if (off1 == 0) {
        a1v = D_0069A578;
    } else {
        char *p1 = (char *)obj1 + off1;
        *p1 = 0;
        a1v = *arg1;
    }
    void *obj2 = *arg2;
    s32 off2 = *(s32 *)((char *)obj2 - 0x10);
    void *a2v;
    if (off2 == 0) {
        a2v = D_0069A578;
    } else {
        char *p2 = (char *)obj2 + off2;
        *p2 = 0;
        a2v = *arg2;
    }
    void *obj3 = *arg3;
    s32 off3 = *(s32 *)((char *)obj3 - 0x10);
    void *a3v;
    if (off3 == 0) {
        a3v = D_0069A578;
    } else {
        char *p3 = (char *)obj3 + off3;
        *p3 = 0;
        a3v = *arg3;
    }
    func_004EE048(*(Netcnf **)((char *)arg0 + 0x268), (s32)a1v, (const char *)a2v, (s32)a3v);
}
