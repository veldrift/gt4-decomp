extern "C" char *func_005316F8(unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);
struct Obj { char pad[0x10c]; int count; };
extern Obj *D_0064B4B4;
extern int D_00863770;
extern "C" void *func_0051B858() {
    D_00863770 = (int)func_005316F8(0x100);
    Obj *p = D_0064B4B4;
    if (p) p->count = 0;
    return func_005A48D8((void *)D_00863770, 0, 0x100);
}
