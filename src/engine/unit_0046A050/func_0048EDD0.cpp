typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 v;
    s32 pad;
} D0048EDDEntry;

extern D0048EDDEntry D_0084967C[];

s32 func_0048EDD0(u32 arg0) {
    if (arg0 < 0xCU) {
        return D_0084967C[arg0].v;
    }
    return -1;
}
