/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00346890(void *, int);
extern "C" void func_00346A90(char *, char *);
extern "C" void func_003EA768(char *);
extern "C" void RaceFreeRun__updateToLogger(char *self) {
    char *logger = self + 0xE920;
    func_00346890(logger, 0);
    char *ghost = self + 0xE84C;
    func_00346A90(logger, *(char **)(self + 0xE5D0));
    *(int *)(ghost + 0x1D0) = 0;
    func_003EA768(self);
}
