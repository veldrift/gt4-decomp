/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned short u16;

extern char D_0087E3F8[];
extern "C" s32 func_005B0880(s32 arg0);

extern "C" s32 func_0058C740(s32 arg0) {
    s32 k = 0x28;
    s32 *slot;
    s32 v;
    s32 sel;
    s32 r;

    slot = (s32 *)(arg0 * k + (s32)D_0087E3F8);
    v = func_005B0880(7);
    sel = v;
    if (arg0 == 0) {
        sel = (u16)sel;
    } else {
        sel = sel >> 16;
    }
    if (sel != 1) {
        slot[0] = 0;
        slot[1] = 2;
        return 0;
    }
    r = slot[0];
    if (r != 0) {
        return r;
    }
    slot[0] = sel;
    slot[1] = 2;
    return 1;
}
