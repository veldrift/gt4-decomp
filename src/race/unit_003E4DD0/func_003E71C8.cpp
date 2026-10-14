/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Box { float min[3]; float max[3]; };
extern "C" int func_003E70B0(Box *, float *, int) throw();
extern "C" void func_003E7110(float *, float *, float *, int, float) throw();

extern "C" int func_003E71C8(Box *b, float *p1, float *p2, int start) {
    int code[2];
    if (start >= 3) return 1;
    code[0] = func_003E70B0(b, p1, start);
    code[1] = func_003E70B0(b, p2, start);
    for (;;) {
        if (code[0] & code[1]) return 0;
        if ((code[0] | code[1]) == 0) return 1;
        int *c = code[0] == 0 ? &code[1] : &code[0];
        float *pt = p2;
        if (code[0] != 0) pt = p1;
        int bits = *c;
        if (bits & 1) {
            func_003E7110(pt, p1, p2, 2, b->min[2]);
        } else if (bits & 2) {
            func_003E7110(pt, p1, p2, 2, b->max[2]);
        } else if (bits & 4) {
            func_003E7110(pt, p1, p2, 1, b->min[1]);
        } else if (bits & 8) {
            func_003E7110(pt, p1, p2, 1, b->max[1]);
        } else if (bits & 0x10) {
            func_003E7110(pt, p1, p2, 0, b->min[0]);
        } else if (bits & 0x20) {
            func_003E7110(pt, p1, p2, 0, b->max[0]);
        }
        *c = func_003E70B0(b, pt, start);
    }
}
