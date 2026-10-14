/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *(*fn)(void *, int); };
extern char *D_00622F4C;
extern "C" void CameraSys__CameraManager__initReplayDisplayEnable(void *, int);
extern "C" void CameraSys__CameraManager__initReplayMode(void *, int);
extern "C" void RaceSplitBattleBase__initializeCameraOption(char *self) {
    char **global = &D_00622F4C;
    Entry *e = (Entry *)(*(char **)(self + 0x64) + 0xD0);
    void *camera = e->fn(self + e->delta, 0);
    CameraSys__CameraManager__initReplayDisplayEnable(camera, *(int *)(*global + 0x39DF0) & 1);
    CameraSys__CameraManager__initReplayMode(camera, *(int *)(*global + 0x39DEC));
}
