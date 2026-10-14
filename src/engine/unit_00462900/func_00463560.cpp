/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_00622F4C;
extern "C" int SystemSoundGetOutputMode(void) throw();
extern "C" float SystemSoundGetOutputModeVolume(int, int) throw();
extern "C" void func_00463378(int, int, int, float, float) throw();

extern "C" void func_00463560(long long arg0) {
    float volume = (float)*(int *)(D_00622F4C + 0x38D18) * 0.0078125f;
    func_00463378(arg0, 0x40, 0x7fffffff,
        volume * SystemSoundGetOutputModeVolume(SystemSoundGetOutputMode(), 3), 1.0f);
}
