/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xB0]; int axis; char padB4[0x20]; float scale; char padD8[0xC]; float width; float height; float offset; };
extern "C" float mWidget__getWindowW(Obj *);
extern "C" float mWidget__getWindowH(Obj *);
extern "C" float func_002D4980(Obj *);
extern "C" int func_0057CE60(void *);
extern "C" float mSelectBar__getBeginPointRatio(Obj *self) {
    float f20;
    float f22;
    float f21;
    float total;
    float neg;
    int axis = self->axis;
    if (axis == 0) f21 = self->width;
    else f21 = self->height;
    if (axis == 0) f22 = mWidget__getWindowW(self);
    else f22 = mWidget__getWindowH(self);
    f20 = f21 + func_002D4980(self);
    total = f20 * (float)(func_0057CE60((char *)self + 0xBC) - 1) + f21 * self->scale;
    neg = -self->offset;
    if (neg < 0.0f) return 0.0f;
    {
        float ratio = neg / total;
        float result = 1.0f - f22 / total;
        if (result <= ratio) return result;
        return ratio;
    }
}
