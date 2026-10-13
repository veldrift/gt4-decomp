typedef int s32;

struct Table;

extern "C" int func_004EDCE8(Table *table, const char *id);
extern "C" char D_0069A578[];

extern "C" void mNetConfPS2__virtual_97(void *arg0, void **arg1) {
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
    func_004EDCE8(*(Table **)((char *)arg0 + 0x268), (const char *)a1v);
}
