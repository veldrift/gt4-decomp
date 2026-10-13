typedef int s32;
typedef unsigned int u32;

struct Entry {
    s32 value;
    s32 pad;
};

extern struct Entry D_00849678[];
extern char D_006AE388[];

s32 func_0048EDA0(u32 arg0) {
    if (arg0 < 0xCU) {
        return D_00849678[arg0].value;
    }
    return (s32)D_006AE388;
}
