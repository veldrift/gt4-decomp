typedef int s32;
typedef unsigned int u32;
typedef long s64;
struct Blk { s64 q[0x102]; };
struct Game { char pad[0x38D40]; Blk blk; };
struct Self { char pad0[0xCC8]; u32 fCC8; char pad1[0xD6C - 0xCCC]; s32 fD6C; char pad2[0xD150 - 0xD70]; Blk blk; };
extern Game *D_00622F4C;
extern "C" void RacePS2Base__virtual_102(Self *self) {
    if (self->fCC8 < 2 || self->fD6C != 0)
        self->blk = D_00622F4C->blk;
}
