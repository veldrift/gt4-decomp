extern "C" int func_0053AD48(void *) throw();
extern "C" void *memcpy(void *, const void *, unsigned);
struct Text { char s[9]; } __attribute__((aligned(8)));
extern Text D_0086B3E8;
extern const Text D_006C3A38;
extern "C" Text *func_0053AD60() {
    if (func_0053AD48(&D_0086B3E8)) {
        memcpy(&D_0086B3E8, &D_006C3A38, 9);
    }
    return &D_0086B3E8;
}
