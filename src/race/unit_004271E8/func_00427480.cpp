typedef int s32;
extern void *D_00622D50;
extern "C" void *exception__structor_0(int);
extern "C" void *func_004274E0(void *p);

extern "C" void func_00427480(void) {
    void **w = &D_00622D50;
    if (*w == 0) {
        void *p = exception__structor_0(0x3DC);
        func_004274E0(p);
        *w = p;
    }
}
