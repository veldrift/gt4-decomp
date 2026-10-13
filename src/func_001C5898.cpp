typedef int s32;

extern "C" void func_001C4BE0(void *arg0);

extern char D_00828778[];

extern "C" void *func_001C5898(s32 arg0) {
    if (arg0 == 0) {
        func_001C4BE0(D_00828778);
        return D_00828778;
    }
    return 0;
}
