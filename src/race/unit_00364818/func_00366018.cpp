struct B;
struct Obj;

extern "C" int func_00365FC8(struct B *b, int row, int col);
extern "C" float func_00365FF0(struct B *b, int row, int col);
extern "C" float DynamicsConductor__GetCourseLength(struct Obj *o);

extern "C" int func_00366018(struct B *b, int row, int col, float *out)
{
    int n = func_00365FC8(b, row, col);
    float f20 = func_00365FF0(b, row, col);
    float len = DynamicsConductor__GetCourseLength((struct Obj *)b);
    float half = len * 0.5f;

    if (half < f20) {
        f20 = f20 - len;
        n += 1;
    } else if (f20 < -half) {
        f20 = f20 + len;
        n -= 1;
    }

    *out = f20;
    return n;
}
