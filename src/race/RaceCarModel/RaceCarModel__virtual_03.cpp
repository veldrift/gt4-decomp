extern "C" {
#include "types.h"
#define NULL 0

struct HumanModel;
void HumanModel__virtual_01(struct HumanModel *arg0, float f);   /* extern */

struct RaceCarModel {
    char pad0[0x1670];
    int unk1670;
    int unk1674;
};

void RaceCarModel__virtual_03(char *arg0) {
    if (((struct RaceCarModel *)arg0)->unk1670 != 0) {
        union { unsigned int i; float f; } c1;
        c1.i = 0x3C888888u;
        HumanModel__virtual_01((struct HumanModel *)(arg0 + 0x5E0), c1.f);
        if (((struct RaceCarModel *)arg0)->unk1674 != 0) {
            union { unsigned int i; float f; } c2;
            c2.i = 0x3C888888u;
            HumanModel__virtual_01((struct HumanModel *)(arg0 + 0xE20), c2.f);
        }
    }
}

}
