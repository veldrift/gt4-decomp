extern "C" void func_00355D60(void *, float);
extern "C" float func_00355D80(void *);
extern "C" void func_00355E40(void *, float);
extern float D_008438DC;

extern "C" float func_00355E88(void *self, float v) {
    float out = func_00355D80(self);
    func_00355E40(self, v);
    float sum = out + v;
    float lim = D_008438DC;
    if (lim < sum) {
        v -= sum - lim;
        out = lim;
    } else {
        out = sum;
    }
    func_00355D60(self, out);
    return v;
}
