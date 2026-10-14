typedef int s32;

struct Blob { long long d[258]; };

extern "C" void RaceBGMPS2__setVolumeRate(void *, float);
extern "C" void func_00460368(void *);

extern "C" void func_0033D080(char *arg0) {
    *(Blob *)(arg0 + 0x9D8) = *(Blob *)(arg0 + 0x1C8);
    *(s32 *)(arg0 + 0x34) = 0;
    func_00460368(arg0 + 0x18);
    RaceBGMPS2__setVolumeRate(arg0, 1.0f);
}
