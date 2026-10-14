typedef int s32;

struct Obj {
    char pad0[4];
    void *vt;
    void *f8;
    void *fC;
    void *f10;
    s32 f14;
    char pad18[0x18];
    s32 f30;
    s32 f34;
};

extern char RaceBGMPS2__vtable[];
extern "C" void func_0033D920(void);
extern "C" void func_0033D928(void);
extern "C" void func_004601A8(void);
extern "C" void func_0033D110(void *, float);
extern "C" void RaceBGMPS2__setVolumeRate(void *, float);
extern "C" s32 RaceBGMBase__structor_0(void *);
extern "C" void GranTurismo4__BGMPlayList__setDefault(void *, s32);
extern "C" void func_00460368(void *);

extern "C" void RaceBGMPS2__structor_0(Obj *arg0) {
    RaceBGMBase__structor_0(arg0);
    arg0->vt = RaceBGMPS2__vtable;
    GranTurismo4__BGMPlayList__setDefault((char *)arg0 + 0x1C8, 0);
    GranTurismo4__BGMPlayList__setDefault((char *)arg0 + 0x9D8, 0);
    arg0->f8 = (void *)func_0033D920;
    arg0->f10 = (void *)func_0033D928;
    arg0->fC = (void *)func_004601A8;
    arg0->f14 = 0;
    func_00460368((char *)arg0 + 0x18);
    arg0->f30 = 0;
    arg0->f34 = 0;
    float one = 1.0f;
    func_0033D110(arg0, one);
    return RaceBGMPS2__setVolumeRate(arg0, one);
}
