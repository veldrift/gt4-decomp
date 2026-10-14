/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void RaceDisplayObjectBase__selectTexture(void *, const char *);
extern "C" int func_003A1E10(const char *);
extern "C" int PDISTD__UNIT_MANAGER;
extern "C" char D_006A15D8[], D_006A15B8[], D_006A15C8[], D_006A15A8[];
extern "C" char D_006A15E8[], D_006A15F0[], D_006A15F8[];
extern "C" char D_006A1608[], D_006A1610[], D_006A1618[], D_006A1620[];
extern "C" void RaceOnboardPanel__init_texset(char *self) {
    RaceDisplayObjectBase__selectTexture(self + 0x50, D_006A15D8);
    RaceDisplayObjectBase__selectTexture(self + 0xB3C, D_006A15B8);
    RaceDisplayObjectBase__selectTexture(self + 0xB80, D_006A15C8);
    RaceDisplayObjectBase__selectTexture(self + 0xBC4, D_006A15A8);
    const char *name = D_006A15E8;
    switch (PDISTD__UNIT_MANAGER) {
    case 0: break;
    case 1: name = D_006A15F0; break;
    default: break;
    }
    RaceDisplayObjectBase__selectTexture(self + 0xC08, name);
    RaceDisplayObjectBase__selectTexture(self, D_006A15F8);
    *(int *)(self + 0x40) = func_003A1E10(D_006A1608);
    *(int *)(self + 0x44) = func_003A1E10(D_006A1610);
    *(int *)(self + 0x48) = func_003A1E10(D_006A1618);
    *(int *)(self + 0x4C) = func_003A1E10(D_006A1620);
}
