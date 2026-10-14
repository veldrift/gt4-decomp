/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { float limit, min, max; const char *name; };
extern Entry D_006A3D38[];
extern "C" char *func_005A609C(char *, const char *) throw();
extern "C" char *func_005A5DC8(char *, const char *);
extern "C" void RaceDisplayObjectBase__selectTexture(void *, const char *);
extern "C" void RaceMeterBase__setScale(void *, float, float);
extern "C" void RaceRoundTachometerBase__setScale(char *self, float scale, float value) {
    char name[128];
    float low = 0.0f;
    Entry *entry = D_006A3D38;
    int i = 0;
    do {
        if (value <= entry->limit) {
            *(float *)(self + 0x890) = 0x1.3e62f4p-2f;
            low = entry->min;
            scale = entry->max;
            func_005A609C(name, self + 0x86C);
            func_005A5DC8(name, entry->name);
            RaceDisplayObjectBase__selectTexture(self, name);
            break;
        }
        ++i;
        ++entry;
    } while (i < 9);
    RaceMeterBase__setScale(self, scale, low);
    *(int *)(self + 0x24) = 0;
}
