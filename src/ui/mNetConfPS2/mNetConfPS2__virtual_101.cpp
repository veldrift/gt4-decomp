typedef int s32;

struct Conn;

extern char D_0069A578[];
extern "C" void func_004ED490(Conn *arg0, const char *arg1, const char *arg2);

extern "C" void func_00275CD0(void *arg0, void **arg1, void **arg2) {
    void *obj = *arg1;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a1v;
    if (off == 0) {
        a1v = D_0069A578;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
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
    func_004ED490(*(Conn **)((char *)arg0 + 0x268), (const char *)a1v, (const char *)a2v);
}
