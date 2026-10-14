extern int RaceCarSound__visual_;
extern "C" float RaceCarSound__getMasterVolume(void);
extern "C" void func_00463378(void *a, void *b, unsigned int c, float x, float y);

extern "C" void func_00393428(void *a, void *b, float x, float y) {
    if (RaceCarSound__visual_ == 0) {
        float s = RaceCarSound__getMasterVolume();
        func_00463378(a, b, 0x7FFFFFFF, x * s, y);
    }
}
