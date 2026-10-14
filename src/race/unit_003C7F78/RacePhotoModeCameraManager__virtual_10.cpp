struct Settings { int x; int value; };
struct Obj { char pad[0xE70]; Settings settings; char pad2[0x108]; int handle; };
extern "C" int func_003C7838(int) throw();
extern "C" float RacePhotoModeCameraManager__virtual_10(Obj *self) {
    Settings *s = &self->settings;
    int active = func_003C7838(self->handle);
    float value = 500.0f;
    if (active != 0) {
        value = (float)s->value / 100.0f;
    }
    return value;
}
