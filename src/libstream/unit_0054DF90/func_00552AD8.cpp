typedef int s32;

struct Pair;
struct Rec;

extern "C" void func_00552B60(struct Pair *base, const struct Rec *r);
extern "C" void func_005A48D8(void *dst, s32 c, s32 n);

extern char D_008A1610[];
extern char D_0064C8C0[];
extern char D_0064CC08[];

extern "C" void func_00552AD8(s32 arg0) {
    struct Pair *base = (struct Pair *)D_008A1610;
    func_005A48D8(base, 0, 0x400);
    func_00552B60(base, (const struct Rec *)D_0064C8C0);
    if (arg0 == 1) {
        return;
    }
    if (arg0 == 2) {
        return func_00552B60(base, (const struct Rec *)D_0064CC08);
    }
}
