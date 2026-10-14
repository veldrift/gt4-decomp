/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_006A0718[];
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_003A5268(void *, const char *, int);
extern "C" void RaceEventDisplay__addEvent(void *, const char *, float, float, float, float);
extern "C" void RaceDisplay__printMessage(char *self, const char *text, unsigned int color, float time) {
    char *lock = self + 0xD8;
    func_00576788(lock);
    char *p = self + 0x17BC;
    if (color == 0) color = 0x80C8C8C8;
    *(unsigned int *)(p + 0x20) = color;
    func_003A5268(p, D_006A0718, 1);
    RaceEventDisplay__addEvent(p, text, time, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    func_005767C0(lock);
}
