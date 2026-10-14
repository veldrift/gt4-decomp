typedef int s32;
struct T { s32 arr[1][2]; };
extern T D_00622DC0;
extern "C" void func_00436978(s32 i, s32 *p, s32 *q) {
    *p = D_00622DC0.arr[i][0];
    *q = D_00622DC0.arr[i][1];
}
