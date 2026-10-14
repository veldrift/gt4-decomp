typedef int s32;

extern "C" void func_00343490(void *);
extern "C" void func_00364868(void *, void *, void *);
extern "C" s32 func_00444190(void *);
extern "C" s32 SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" s32 func_004443A8(void *, s32);

extern "C" s32 func_00364908(void *arg0, void *arg1) {
    char buf[0x180];
    func_00444190(buf);
    char buf2[0x20];
    func_00343490(buf2);
    if (func_004443A8(buf, (s32)arg1) == 0) {
        SPEC_DATABASE__CarEquipments__setVariationOrder(buf, 2);
        return 0;
    }
    func_00364868(arg0, buf, buf2);
    SPEC_DATABASE__CarEquipments__setVariationOrder(buf, 2);
    return 1;
}
