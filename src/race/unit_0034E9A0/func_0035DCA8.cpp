typedef int s32;

typedef struct {
    char b[32];
} Block_0035DCA8;

typedef struct {
    char pad0[0x6D8];
    s32 zero;
    Block_0035DCA8 blk;
} Dst_0035DCA8;

void func_0035DCA8(Dst_0035DCA8 *arg0, const Block_0035DCA8 *arg1) {
    arg0->blk = *arg1;
    arg0->zero = 0;
}
