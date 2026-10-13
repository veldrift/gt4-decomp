typedef float f32;

extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatAngleOffset(void *arg0);

extern "C" f32 SpecialCarGeometry__GetChairAngle(void) {
    void *p = DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
    if (p) {
        return DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatAngleOffset(p) + 0x1.14E0D0p+0f;
    }
    return 0x1.14E0D0p+0f;
}
