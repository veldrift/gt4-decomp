extern "C" void *func_0044F4C0(void *);
extern "C" float func_0044F9B0(void *);

extern "C" float SpecialCarGeometry__GetChairAngle(void *arg0) {
    void *geometry = func_0044F4C0(arg0);
    if (geometry != 0) {
        return func_0044F9B0(geometry) + 0x1.14e0d00000000p+0f;
    }
    return 0x1.14e0d00000000p+0f;
}
