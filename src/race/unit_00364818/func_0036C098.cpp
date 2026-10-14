/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct O {
    char pad[0x488];
    float f488, f48C;
    char pad2[0x527 - 0x490];
    u8 b527, b528, b529;
};
extern "C" void func_0036C098(O *o) {
    int v = -1;
    if (!(o->f488 <= 0.0f)) v = (int)((1.0f - o->f488) * 3.0f);
    if (o->f48C == 1.0f) v = 0;
    if (o->b528 != 0) o->b528 = o->b528 - 1;
    int a1 = o->b527;
    if (v != a1 && v != -1) {
        int nv;
        if (v < a1) {
            o->b529 = o->b529 + 1;
            if (o->b529 < 0xD) return;
            nv = a1 + 0xFF;
        } else {
            o->b529 = o->b529 + 1;
            if (o->b529 < 0x3D) return;
            nv = a1 + 1;
        }
        volatile O *dst = o;
        dst->b528 = 0x3C;
        dst->b527 = nv;
    }
    o->b529 = 0;
}
