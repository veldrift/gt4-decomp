/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block {
    long w[0x2F];
};

struct Owner {
    char pad[0x130];
    Block block;
};

extern "C" void func_003EDD80(Owner *o, const Block *b) {
    o->block = *b;
}
