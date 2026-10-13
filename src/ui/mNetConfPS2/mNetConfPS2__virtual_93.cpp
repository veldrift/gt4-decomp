typedef int s32;

extern char D_0069A578[];
extern "C" void func_004ED980(void *conn, void *value, const char *name, const char *text);

extern "C" void func_002755B0(void *arg0, void *arg1, void **arg2, void **arg3) {
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
    func_004ED980(*(void **)((char *)arg0 + 0x268), arg1, (const char *)a2v, (const char *)a3v);
}
