struct Six { char pad[0x70]; void *f70; };
struct RT { char pad0[0x6C]; Six *f6C; char pad70[0xD68 - 0x70]; int fD68; };
extern "C" int RaceBase__getLicenseSubNumber(int);
extern "C" int RaceBase__getLicenseSubMode(int);
extern "C" int SPEC_DATABASE__RaceSpec__getRaceLabel(void *);

extern "C" int RaceTraining__getRaceMode(RT *self, int *out) {
    int *p = &self->fD68;
    *out = -1;
    int v = *p;
    if ((v ^ 3) == 0) {
        int s0 = SPEC_DATABASE__RaceSpec__getRaceLabel(self->f6C->f70);
        int s1 = RaceBase__getLicenseSubMode(s0);
        if (s1 == 0)
            return *p;
        *out = RaceBase__getLicenseSubNumber(s0);
        return s1;
    }
    return v;
}
