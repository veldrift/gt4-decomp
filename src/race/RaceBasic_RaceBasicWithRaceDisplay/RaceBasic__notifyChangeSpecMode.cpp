/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; void (*fn)(void *, int); };
extern "C" void RaceBase__notifyChangeSpecMode(void);
extern "C" void RaceBasic__notifyChangeSpecMode(char *self) {
    RaceBase__notifyChangeSpecMode();
    char *o = *(char **)(self + 0xE420);
    if (o) {
        VE *e = (VE *)(*(char **)o + 0x40);
        e->fn(o + e->d, *(int *)(self + 0xCC8));
    }
}
