/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect {
    float x, y, w, h;
    void set(float v) { x = v; y = v; w = v; h = v; }
    Rect() { set(0.0f); }
};
struct VE { short delta, index; void (*fn)(void *, Rect *, Rect *); };
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" float func_002313E0(void *);
extern "C" float func_00231400(void *);
extern "C" void mWidget__getWindowSize(void *, float *, float *);
extern "C" void func_00120CF0(void *, void *, Rect *);
extern "C" void mLoggerFace__virtual_70(char *self, char *arg1, int arg2) {
    void **slot = (void **)(self + 0xA4);
    mWidget__virtual_70(self, arg1, 0);
    if (arg2 != 0 && __builtin_expect((int)*slot, 0)) {
        Rect rc;
        Rect out;
        rc.x = func_002313E0(arg1);
        rc.y = func_00231400(arg1);
        mWidget__getWindowSize(self, &rc.w, &rc.h);
        VE *e = (VE *)(*(char **)(arg1 + 4) + 0x1F8);
        e->fn(arg1 + e->delta, &out, &rc);
        func_00120CF0(*slot, arg1, &out);
    }
}
