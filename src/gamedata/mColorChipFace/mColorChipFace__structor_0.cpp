typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
extern Rep D_00659FA8;
extern void *mColorChipFace__vtable;
extern "C" void *mWidget__structor_0(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_00210810(void *);
extern "C" void *func_005A48D8(void *, s32, s32);
extern "C" void *mColorChipFace__structor_0(void *self) {
    void *base = mWidget__structor_0(self);
    (void)base;
    Rep *rep = &D_00659FA8;
    *(void **)((char *)self + 4) = &mColorChipFace__vtable;
    char **slot = (char **)((char *)self + 0xA0);
    for (s32 count = 1; count != -1; --count) {
        char *value;
        if (rep->sel != 0) {
            value = func_005C2560(rep);
        } else {
            value = (char *)rep + 0x10;
            ++rep->ref;
        }
        *slot = value;
        slot = (char **)((char *)slot + 4);
    }
    func_00210810((char *)self + 0xA8);
    func_00210810((char *)self + 0xAC);
    *(short *)((char *)self + 0xB0) = 0;
    return func_005A48D8((char *)self + 0xD4, 0, 8);
}
