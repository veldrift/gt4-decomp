typedef int s32;
extern "C" s32 func_00444190(void *);
extern "C" s32 func_004443A8(void *, const char *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" float func_00130540(void *);
extern "C" float func_001305A0(const char *label) {
    s32 record[96];
    float score;
    func_00444190(record);
    if (!func_004443A8(record, label)) {
        SPEC_DATABASE__CarEquipments__setVariationOrder(record, 2);
        return 0.0f;
    }
    score = func_00130540(record);
    SPEC_DATABASE__CarEquipments__setVariationOrder(record, 2);
    return score;
}
