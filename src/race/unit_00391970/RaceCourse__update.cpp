/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Settings { char pad[0x38d24]; int flag0, vol0; char pad2[8]; int flag1, vol1; };
struct Fade { float value, step, target; };
extern Settings *D_00622F4C;
extern Fade D_0088F2D0;
extern float D_006213D8;
static inline float enabled(int sel) {
    return (sel ? D_00622F4C->flag1 : D_00622F4C->flag0) ? 1.0f : 0.0f;
}
extern "C" void RaceCourse__update(int sel) {
    float v = enabled(sel);
    if (sel) v *= (float)D_00622F4C->vol1 * 0.0078125f;
    else v *= (float)D_00622F4C->vol0 * 0.0078125f;
    Fade *f = &D_0088F2D0;
    f->value += f->step;
    if (f->step >= 0.0f) {
        if (f->target < f->value) f->value = f->target;
    } else {
        if (f->value < f->target) f->value = f->target;
    }
    v *= D_0088F2D0.value;
    D_006213D8 = v;
}
