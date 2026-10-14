typedef unsigned char u8;
typedef int s32;

struct S { char pad[0xC]; u8 bC; u8 bD; u8 bE; u8 bF; };
extern "C" struct S D_006CE4F0;

extern "C" s32 func_00583B50(void) {
    return (D_006CE4F0.bC << 24) | (D_006CE4F0.bD << 16) | (D_006CE4F0.bE << 8) | D_006CE4F0.bF;
}
