/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0xF8A0]; int count; };
extern "C" void *func_0034C190(Self *, int);
extern "C" void DynamicsConductorLicense__LicenseRunTimeJudge(Self *, void *);
extern "C" int DynamicsConductor__ProcessLapTimeCommonPost(Self *);
extern "C" int DynamicsConductorLicense__ProcessLapTimeCommonPost(Self *self) {
    for (int i = 0; i < self->count; i++) {
        DynamicsConductorLicense__LicenseRunTimeJudge(self, func_0034C190(self, i));
    }
    return DynamicsConductor__ProcessLapTimeCommonPost(self);
}
