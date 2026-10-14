typedef float f32;

extern "C" void AutomaticFader__fadein(char *o, f32 t);

extern "C" void RaceLicenseDisplay__virtual_57(char *self) {
    f32 zero = 0.0f;
    AutomaticFader__fadein(self + 0x14D0, zero);
    AutomaticFader__fadein(self + 0x15B0, zero);
}
