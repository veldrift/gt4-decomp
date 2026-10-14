/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    int m0;
    char pad[0x90];
    int m94;
};
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_004EF730(O *, int, int, void *, int);

extern "C" unsigned int func_004EEBB8(O *o, void *buf) {
    if (o->m0 == 0) {
        return 0;
    }
    func_005A48D8(buf, 0, 0x10);
    return (unsigned int)~func_004EF730(o, o->m94, 0xD, buf, 0x10) >> 31;
}
