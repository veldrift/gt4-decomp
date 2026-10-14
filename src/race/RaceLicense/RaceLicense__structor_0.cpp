/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char RaceLicense__vtable[];
extern "C" int RaceSolitaire__structor_0(char *self);
extern "C" void RacePause__structor_0(void *);
extern "C" void RaceLicenseBGM__structor_0(void *) throw();
extern "C" void RaceLicenseDisplay__structor_0(void *);
extern "C" void DynamicsConductorLicense__structor_3(void *);
extern "C" void ResultLicense__structor_0(void *);
extern "C" void LicenseConcourse__structor_0(void *);
extern "C" void func_0038BB50(void *, void *);
extern "C" void func_003C31C8(void *, void *);
extern "C" void func_003E1B28(void *, void *);
extern "C" void func_003BC5A8(void *, int);
extern "C" int RaceLicense__structor_0(char *self) {
    char *s1 = self + 0xF140;
    RaceSolitaire__structor_0(self);
    *(char **)(self + 0x64) = RaceLicense__vtable;
    RacePause__structor_0(s1);
    RaceLicenseBGM__structor_0(self + 0xF178);
    RaceLicenseDisplay__structor_0(self + 0x10368);
    DynamicsConductorLicense__structor_3(self + 0x146F0);
    ResultLicense__structor_0(self + 0x24838);
    LicenseConcourse__structor_0(self + 0x24E5C);
    *(void **)(self + 0x74) = self + 0xF178;
    func_0038BB50(self, self + 0x10368);
    *(void **)(self + 0x70) = self + 0x146F0;
    *(int *)(s1 + 0x28) = 1;
    func_003C31C8(s1, self + 0xE350);
    func_003E1B28(self + 0x24838, self + 0xE350);
    func_003BC5A8(self, 0);
    *(int *)(self + 0xD68) = 3;
    *(int *)(self + 0xCF30) = 0;
}
