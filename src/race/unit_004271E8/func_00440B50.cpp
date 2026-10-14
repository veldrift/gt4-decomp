typedef long long s64;
typedef int s32;
struct Slot { s64 q[47]; };
struct Self { s64 pad; Slot slots[3]; s64 pad2[4]; s32 cur; };
extern "C" void func_00440268(Self *, s64, s32);
extern "C" void func_004402F0(Self *, s64, s32);
extern "C" void func_004403C0(Self *, s64, s32);
extern "C" void func_00440430(Self *, s64, s32);
extern "C" void func_004404B8(Self *, s64, s32);
extern "C" void func_004406C8(Self *, s64, s32);
extern "C" void func_004407B0(Self *, s64, s32);
extern "C" void func_00440820(Self *, s64, s32);
extern "C" void func_004408D8(Self *, s64, s32);
extern "C" void func_004468F8(Slot *, s64);
extern "C" s32 func_00443240(Slot *);
extern "C" void func_00440B50(Self *self, s64 p, s32 x) {
    s32 id = (s32)(p >> 32);
    Slot *slot = &self->slots[self->cur];
    switch (id) {
    case 1:
        slot->q[4] = p;
        break;
    case 2:
        func_00440268(self, p, x);
        break;
    case 3:
        func_004404B8(self, p, x);
        break;
    case 4:
        func_00440820(self, p, x);
        break;
    case 5:
        func_004407B0(self, p, x);
        break;
    case 8:
        for (s32 i = 0; i < 3; i++) self->slots[i].q[15] = p;
        break;
    case 10:
        func_004403C0(self, p, x);
        break;
    case 11:
        func_004402F0(self, p, x);
        func_00443240(slot);
        break;
    case 13:
        slot->q[21] = p;
        break;
    case 14:
        func_00440430(self, p, x);
        break;
    case 15:
        for (s32 i = 0; i < 3; i++) self->slots[i].q[17] = p;
        break;
    case 16:
        for (s32 i = 0; i < 3; i++) self->slots[i].q[18] = p;
        break;
    case 17:
        for (s32 i = 0; i < 3; i++) self->slots[i].q[19] = p;
        break;
    case 18:
        slot->q[20] = p;
        break;
    case 19:
        slot->q[27] = p;
        break;
    case 20:
        slot->q[26] = p;
        break;
    case 21:
        slot->q[24] = p;
        break;
    case 22:
        slot->q[23] = p;
        break;
    case 23:
        slot->q[25] = p;
        break;
    case 24:
        func_004406C8(self, p, x);
        break;
    case 25:
        slot->q[12] = p;
        break;
    case 26:
        slot->q[13] = p;
        break;
    case 29:
        for (s32 i = 0; i < 3; i++) self->slots[i].q[30] = p;
        break;
    case 27:
        func_004408D8(self, p, x);
        break;
    case 28:
        slot->q[33] = p;
        break;
    case 30:
        for (s32 i = 0; i < 3; i++) self->slots[i].q[32] = p;
        break;
    case 31:
        for (s32 i = 0; i < 3; i++) func_004468F8(&self->slots[i], p);
        break;
    }
}
