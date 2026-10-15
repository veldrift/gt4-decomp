/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Random {
    int seed;
    Random(int) __asm__("func_005792E8");
    float range(float, float) __asm__("func_005792F0");
};
struct CarInfo { unsigned long word0; short unknown8, unknownA, year, unknownE; unsigned long word10; };
struct Limits { int low, high;
    int operator[](int index) const { return (&low)[index]; }
};
extern Limits D_006A6910[];
extern "C" void *func_00441248(void *);
extern "C" int func_00445808(void *);
extern "C" unsigned long func_004454C0(void *);
extern "C" int func_00448820(unsigned long, CarInfo *);
extern "C" void func_00441298(void *, int);
extern "C" void func_003434A8(void *, int);
extern "C" void func_00343578(void *, float);
extern "C" void func_00343978(void *, float);
extern "C" void func_00343698(void *, float);
extern "C" void func_003438A0(void *, float);
static inline float year_range(Random &random, int year, Limits *base) {
    int index = year - 1990;
    if (index < 0) index = 0;
    if (index > 14) index = 14;
    Limits *limits = base + index;
    return random.range((float)((*limits)[0] * 1000000), (float)((*limits)[1] * 1000000));
}
extern "C" void func_00440FB8(void *car, int seed, int first, int second) {
    Random random(seed);
    void *engine = (char *)car + 0x4A0;
    if (first < 0) first = (int)random.range(0.0f, (float)func_00445808(func_00441248(car)));
    func_00441298(car, first);
    if (second < 0) {
        CarInfo info;
        func_00448820(func_004454C0(func_00441248(car)), &info);
        second = (int)year_range(random, info.year, D_006A6910);
    }
    float value = (float)second;
    func_003434A8(engine, second);
    func_00343578(engine, value);
    func_00343978(engine, value);
    func_00343698(engine, value);
    func_003438A0(engine, value);
    func_003438A0(engine, 0.0f);
}
