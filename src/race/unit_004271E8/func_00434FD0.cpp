/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car {
    long long id;
    long long w;
};
struct SRC { char pad[0x10]; };
extern "C" void ShowRoomCar__structor_0(SRC *);
extern "C" void ShowRoomCar__structor_1(SRC *, int);
extern "C" void func_00364868(SRC *, int, int);
extern "C" float func_00364E78(SRC *, void *);
extern "C" int func_00364FA8(SRC *, int);
extern "C" int func_00441248(int);
extern "C" int func_00448820(long long, void *);
extern "C" int func_004489A0(void *, int);

extern "C" void func_00434FD0(Car *car, int arg1) {
    SRC s;
    char sp10[16];
    char sp20[32];
    int r;
    const int M = 0x3FFFF;
    ShowRoomCar__structor_0(&s);
    int part = arg1 + 0x4A0;
    int v = func_00441248(arg1);
    func_00364868(&s, v, part);
    r = 0;
    float f = func_00364E78(&s, sp10);
    unsigned long long u = (unsigned)(int)(f * 100.0f);
    car->w = (car->w & -134217217LL) | ((u & M) << 9);
    int d = func_00364FA8(&s, 0x6B67);
    car->w = (car->w & 0xFFFFE000FFFFFFFFLL) | ((unsigned long long)(d & 0x1FFF) << 32);
    if (func_00448820(car->id, sp20) != 0) {
        r = func_004489A0(sp20, 3) != 0;
    }
    if (r != 0) {
        car->w = car->w & -134217217LL & 0xFFFFE000FFFFFFFFLL;
    }
    ShowRoomCar__structor_1(&s, 2);
}
