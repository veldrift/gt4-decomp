typedef int s32;

extern s32 D_0064A558;

struct U4 {
    s32 v;
} __attribute__((packed));

extern "C" s32 func_0050F3E8(struct U4 *arg0, struct U4 arg1) {
    *arg0 = arg1;
    D_0064A558++;
    return 4;
}
