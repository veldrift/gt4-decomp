/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;

extern s32 D_00658368[];
extern s32 D_00658360;
extern char D_005B73C8[];
extern char D_005B7390[];

extern "C" s32 func_005B7408(s32, s32, s32);
extern "C" void func_005B7550(s32, s32);

extern "C" void func_005B7450(void) {
    s32 *g = D_00658368;
    s32 s3;
    s32 s2;
    u32 s1;
    u32 s0;

    func_005B7550(g[0], g[1]);
    func_005B7550(g[2], g[3]);

    s3 = func_005B7408(0x80000000, 0x80080000, (s32)D_005B73C8);
    s1 = (u32)s3 - 0x20C;
    s2 = func_005B7408(0x80000000, 0x80080000, (s32)D_005B7390);
    s0 = (u32)s2 - 0x168;

    if (s1 != s0) {
        do {
            if (s1 < s0) {
                s3 = func_005B7408(s3 + 4, 0x80080000, (s32)D_005B73C8);
                s1 = (u32)s3 - 0x20C;
            } else {
                s2 = func_005B7408(s2 + 4, 0x80080000, (s32)D_005B7390);
                s0 = (u32)s2 - 0x168;
            }
        } while (s1 != s0);
    }

    D_00658360 = (s32)s1;
}
