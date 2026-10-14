struct Settings { int x; int value; float range; };
struct Obj { char pad[0xE70]; Settings settings; char pad2[0x104]; int handle; };
extern "C" float func_003C7928(int, float, float, float, float) throw();
extern "C" float RacePhotoModeCameraManager__virtual_09(Obj *self) {
    Settings *s = &self->settings;
    float value = s->range;
    int active = value <= 0.0f;
    if (active != 0) {
        float result = func_003C7928(self->handle, (float)s->value / 100.0f,
                             35.0f, 0x1.555554p+0f, 0x1.111110p-10f);
        if (result < 1.0f) result = 1.0f;
        return result;
    }
    return value;
}
