typedef int s32;
struct HSymID_0030B358 { s32 value_0; };
struct HObject_0030B358;
struct Ref_0030B358;
typedef void (HObject_0030B358::*Operator_0030B358)(Ref_0030B358 &, const Ref_0030B358 &, s32, const Ref_0030B358 *);
struct OperatorEntry_00619CA8 {
    const HSymID_0030B358 *key_0;
    Operator_0030B358 member_4;
};
extern const OperatorEntry_00619CA8 D_00619CA8[];
extern const Operator_0030B358 D_0069DE80;
extern "C" Operator_0030B358 func_0030B358(const HSymID_0030B358 *symbol) {
    const OperatorEntry_00619CA8 *entry = D_00619CA8;
    s32 index = 0;
    do {
        if (symbol->value_0 == entry->key_0->value_0) return entry->member_4;
        ++index;
        ++entry;
    } while (index < 28);
    return D_0069DE80;
}
