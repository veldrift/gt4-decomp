/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void RaceEntryCar__clear(void *, int);
extern "C" void RaceEntryCar__updateBodyColor(void *);
extern "C" void func_003C08C0(void *, int, int);
extern "C" void setCarEquipment(char *, char *);
static inline void setFlag(char *p, int flag) { *(int *)(p + 0x198) = flag; }
static inline void loadGhost(char *race, char *src, int flag) {
    func_003C08C0(race, 2, 0);
    char *p = *(char **)(*(char **)(*(char **)(race + 0x60) + 8) + 4);
    RaceEntryCar__clear(p, 1);
    setCarEquipment(p, src + 0x960);
    setFlag(p, flag);
    RaceEntryCar__updateBodyColor(p);
}

extern "C" void RaceBase__loadGhostData(char *self,char *src) { loadGhost(*(char **)(self+0x6c),src,1); }
