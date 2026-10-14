/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pool;
struct Block {
    Pool *owner;
    int a4, a8, aC;
    char *free, *first, *last;
};
struct Pool {
    char pad[0x38];
    Block *cached;
    int used, size, count;
};
extern "C" void *func_00578CF0(int, int);
extern "C" Block *func_00328A80(Pool *self) {
    Block *r = self->cached;
    if (r != 0) {
        self->cached = 0;
    } else {
        int stride = self->size;
        int count = self->count;
        stride += 4;
        int bytes = stride * count;
        Block *b = (Block *)func_00578CF0(16, bytes + 28);
        b->owner = self;
        b->a4 = 0;
        b->a8 = 0;
        b->aC = 0;
        b->free = 0;
        b->first = 0;
        b->last = 0;
        if (bytes != 0) {
            b->first = (char *)(b + 1);
            b->last = b->first + stride * (count - 1);
            char *p = b->first;
            while (p < b->last) {
                *(char **)p = p + stride;
                p += stride;
            }
            *(int *)b->last = 0;
            b->free = b->first;
        }
        r = b;
    }
    self->used += self->count;
    return r;
}
