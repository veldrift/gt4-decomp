/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char *AutomobileControlRecord__Manager__load(void *, char *, int);
extern "C" void RaceFreeRun__loadReplayTheathre(char *self, char *replay) {
    *(int *)(self + 0xF054) = 1;
    char *ghost = self + 0xE84C;
    AutomobileControlRecord__Manager__load(self + 0xE920, replay + 0x1AA4, 0);
    *(int *)(ghost + 0x1D0) = 0;
}
