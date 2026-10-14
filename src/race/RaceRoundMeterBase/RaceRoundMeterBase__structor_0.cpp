struct RaceRoundMeterBase {
    char p0[0x14];
    void *vtbl;
    char p18[0xC];
    int u24;
    int u28;
    int u2C;
    float u30;
    unsigned char u34;
    char p35[0x1B];
    float u50;
    float u54;
};

extern char RaceRoundMeterBase__vtable[];
extern float D_006A28A0;

extern "C" void *RaceMeterBase__structor_1(struct RaceRoundMeterBase *self);
extern "C" void RaceMeterBase__setScale(struct RaceRoundMeterBase *self, float a, float b);
extern "C" void func_003BE808(struct RaceRoundMeterBase *self, float a, float b);
extern "C" void func_003BE818(struct RaceRoundMeterBase *self, float a, float b);
extern "C" void func_003BE828(struct RaceRoundMeterBase *self, float a, float b);

extern "C" void RaceRoundMeterBase__structor_0(struct RaceRoundMeterBase *arg0) {
    RaceMeterBase__structor_1(arg0);
    float f = D_006A28A0;
    arg0->vtbl = RaceRoundMeterBase__vtable;
    arg0->u28 = (int)0x80000000;
    arg0->u30 = f;
    arg0->u2C = (int)0x80FFFFFF;
    arg0->u34 = 8;
    arg0->u24 = 0;
    func_003BE808(arg0, 0.5f, 0.5f);
    func_003BE818(arg0, 150.0f, 1.0f);
    RaceMeterBase__setScale(arg0, 0.0f, 1.0f);
    func_003BE828(arg0, 65.0f, 295.0f);
    arg0->u50 = -0x1.999998p-4f;
    arg0->u54 = 0x1.e66666p-1f;
}
