extern char RacePriusPanel__vtable[];
extern char D_006A1638[];

extern "C" void *RacePanel__structor_1(void *arg0);
extern "C" void RaceDigitalSpeedmeter__structor_1(void *arg0);
extern "C" void func_003A40F8(void *arg0, const char *arg1);
extern "C" void RaceGasMileageDisplay__structor_0(void *arg0);
extern "C" void RaceGasConsumptionDisplay__structor_0(void *arg0);
extern "C" void RacePriusHybridDisplay__structor_1(void *arg0);
extern "C" int func_003A9608(void *arg0);
extern "C" void Oscillator__setCycle(void *arg0, float f12, float f13);
extern "C" void Oscillator__setWaveform(void *arg0, float f12, float f13);
extern "C" void Oscillator__setCount(void *arg0, int a1, unsigned char a2);

extern "C" void RacePriusPanel__structor_1(void *arg0) {
    char *s1 = (char *)arg0 + 0x3C;
    char *s2 = (char *)arg0 + 0x22C;
    RacePanel__structor_1(arg0);
    char *s4 = (char *)arg0 + 0xE0;
    *(void **)((char *)arg0 + 0x14) = RacePriusPanel__vtable;
    RaceDigitalSpeedmeter__structor_1(s1);
    char *s3 = (char *)arg0 + 0x74;
    RaceGasMileageDisplay__structor_0(s3);
    RaceGasConsumptionDisplay__structor_0(s4);
    RacePriusHybridDisplay__structor_1((char *)arg0 + 0x150);
    func_003A9608(s2);
    *(int *)(s1 + 0x2C) = (int)0x80E3B896;
    func_003A40F8(s1, D_006A1638);
    *(int *)(s3 + 0x18) = (int)0x80B58F43;
    *(int *)(s4 + 0x18) = (int)0x800363FD;
    Oscillator__setCycle(s2, 0x1.999998p-3f, 0.5f);
    Oscillator__setWaveform(s2, 0.0f, 0x1.1eb850p-4f);
    return Oscillator__setCount(s2, -1, 0);
}
