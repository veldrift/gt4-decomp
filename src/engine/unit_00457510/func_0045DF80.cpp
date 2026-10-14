/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_0045DBB8[];
extern "C" void func_00395A38(void *, void *, void *, int, float, float, float, float);
extern "C" void func_0045DF80(char *p) {
    char *v = p + 8;
    float xmax = *(float *)(v + 0x18);
    float ymax = *(float *)(v + 0x1c);
    float xmin = xmax;
    float ymin = ymax;
    for (int i = 1; i < 8; i++, v += 0x44) {
        float x = *(float *)(v + 0x18);
        float y = *(float *)(v + 0x1c);
        if (x < xmin) xmin = x;
        if (xmax < x) xmax = x;
        if (y < ymin) ymin = y;
        if (ymax < y) ymax = y;
    }
    func_00395A38(*(void **)(p + 0x488), D_0045DBB8, p, *(int *)(p + 0x484), xmin, -ymax, xmax, -ymin);
}
