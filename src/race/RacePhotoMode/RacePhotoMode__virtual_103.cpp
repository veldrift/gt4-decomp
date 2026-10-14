struct Blk { long q[0x102]; };
struct Game { char pad[0x39550]; Blk blk; };
struct Self { char pad[0xD960]; Blk blk; };
extern Game *D_00622F4C;
extern "C" void RacePhotoMode__virtual_103(Self *self) {
    D_00622F4C->blk = self->blk;
}
