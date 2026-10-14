/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Ctl {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    char pad28[0x4];
    s32 unk2C;
    s32 unk30;
};

static inline bool between(float x, float a, float b) {
    bool r = false;
    float d = x - a;
    if (0.0f <= d && d <= b - a) r = true;
    return r;
}
extern "C" void func_002CDB30(Ctl *self) {
    float step = self->unk24 / 60.0f;
    float target;
    float current;
    bool flag;
    if (self->unk2C != 0) target = self->unk1C;
    else target = self->unk18;
    if (self->unk30 != 0) {
        current = self->unk20;
        float next = current + step;
        flag = between(target, current, next);
        if (flag == 0) {
            self->unk20 += step;
            return;
        }
        self->unk20 = target;
        return;
    }
    current = self->unk20;
    float next = current - step;
    flag = between(target, next, current);
    if (flag != 0) {
        self->unk20 = target;
    } else {
        self->unk20 -= step;
    }
}
