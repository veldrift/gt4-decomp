/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef long long s64;
struct Car { char pad[0x10]; };
struct Obj { char pad[0x174]; s32 f174; s32 f178; char pad2[0x8]; s32 f184; };
extern "C" {
s32 func_00147D80(Obj *);
void ShowRoomCar__structor_0(Car *);
void ShowRoomCar__structor_1(Car *, s32);
void func_00364868(Car *, s32, s32);
f32 func_00364E78(Car *, s32 *);
f32 func_00364EB8(Car *, s32 *);
s32 func_00364FA8(Car *, s32);
s32 func_00441248(s32);
s32 func_004454C0(s32);
s32 func_00448820(s32, s32 *);
s32 func_004489A0(s32 *, s32);

void func_00146648(Obj *arg0) {
    Car car;
    s32 sp10[4];
    s32 sp20[8];
    s32 var_s3 = 0;
    s32 s1 = func_00441248(func_00147D80(arg0));
    ShowRoomCar__structor_0(&car);
    func_00364868(&car, s1, func_00147D80(arg0) + 0x4A0);
    arg0->f178 = (s32)(func_00364E78(&car, sp10) * 100.0f);
    arg0->f184 = (s32)(func_00364EB8(&car, sp10) * 100.0f);
    arg0->f174 = func_00364FA8(&car, 0x6B67);
    if (func_00448820(func_004454C0(s1), sp20) != 0) {
        var_s3 = func_004489A0(sp20, 3) != 0;
    }
    if (var_s3 != 0) {
        arg0->f178 = 0;
        arg0->f184 = 0;
        arg0->f174 = 0;
    }
    ShowRoomCar__structor_1(&car, 2);
}
}
