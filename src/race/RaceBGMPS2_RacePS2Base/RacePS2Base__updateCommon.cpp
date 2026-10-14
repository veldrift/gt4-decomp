typedef int s32;
extern "C" s32 RaceBase__updateCommon(void *);
extern "C" void RaceBase___terminate(void *);
extern "C" void ErrorEventView__update(void *, void *);
extern "C" s32 RacePS2Base__updateCommon(char *arg0) {
    if (*(s32 *)(arg0 + 0xD80) != 0) {
        RaceBase___terminate(arg0);
        return 0;
    }
    ErrorEventView__update(arg0 + 0xCF68, *(void **)(arg0 + 0x6C));
    return RaceBase__updateCommon(arg0);
}
