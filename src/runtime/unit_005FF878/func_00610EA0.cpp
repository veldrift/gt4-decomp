typedef int s32;

typedef struct {
    s32 w[11];
} Blk_00610EA0;

typedef struct {
    char pad0[0x30];
    Blk_00610EA0 blk;
} Src_00610EA0;

void *func_00610EA0(void *arg0, const Src_00610EA0 *arg1) {
    *(Blk_00610EA0 *)arg0 = arg1->blk;
    return arg0;
}
