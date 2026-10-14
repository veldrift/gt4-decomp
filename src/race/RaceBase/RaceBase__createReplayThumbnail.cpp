/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void (*fn)(void *, void *); };
extern "C" void RaceBase__createReplayThumbnail(char *self, char *out) {
    Entry *e = (Entry *)(*(char **)(self + 0x64) + 0x1a8);
    e->fn(self + e->delta, out);
    char *car = **(char ***)(*(char **)(*(char **)(self + 0x6c) + 0x60) + 8);
    int value = *(int *)(car + 0x1b0);
    if (!value) value = *(int *)(self + 0xd1c);
    *(int *)(out + 0xd0) = value;
    *(int *)(out + 0xd4) = 0;
    int mode = *(int *)(self + 0xcc4);
    int flag = 0;
    if (mode == 1 || mode == 3) flag = 1;
    *(int *)(out + 0xe0) = flag;
    void (*cb)(void *, void *) = *(void (**)(void *, void *))(self + 0xd20);
    if (cb) cb(out, *(void **)(self + 0xd24));
}
