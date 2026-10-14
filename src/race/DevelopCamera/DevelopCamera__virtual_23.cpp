/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { long w[8]; } __attribute__((aligned(8)));
extern "C" void DevelopCamera__virtual_23(char *self, const Blk *src, float f) {
    Blk *dst = (Blk *)(self + 0x9C0);
    *dst = *src;
    *(float *)((char *)dst + 0x40) = f;
}
