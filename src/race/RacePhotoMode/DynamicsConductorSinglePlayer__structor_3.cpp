extern "C" void RacePS2Base__structor_1(void *, void *);
extern "C" void DynamicsConductor__structor_1(void *, int);
extern "C" void func_00377D20(void *, int);
extern "C" void PhotoModeInput__structor_1(void *, int);
extern "C" void free(int) throw();
extern "C" void func_005C1628(void *) throw();
extern char RacePhotoMode__vtable[];
extern char RacePhotoModeCameraManager__vtable[];
extern char DynamicsConductorSinglePlayer__vtable[];
extern "C" void DynamicsConductorSinglePlayer__structor_3(char *self, int flags) {
    *(int *)(self + 0x64) = (int)RacePhotoMode__vtable;
    free(*(int *)(self + 0x1E658));
    {
        char *p = self + 0x1E680;
        *(int *)p = (int)RacePhotoModeCameraManager__vtable;
        func_00377D20(p, 0);
    }
    PhotoModeInput__structor_1(self + 0x1E548, 2);
    {
        char *p = self + 0xE400;
        *(int *)(p + 0x10140) = (int)DynamicsConductorSinglePlayer__vtable;
        DynamicsConductor__structor_1(p, 0);
    }
    RacePS2Base__structor_1(self, 0);
    if (flags & 1) return func_005C1628(self);
}
