/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct State { u32 h[4]; u32 count[2]; char rest[0x48]; };
extern "C" void func_00547200(State *, const void *, u32) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_006C82E0(void *, const void *, unsigned int);
extern "C" char D_0064C340[];
extern "C" void func_00547360(void *out, State *s) {
    unsigned char bits[8];
    u32 count[2];
    count[0] = s->count[0];
    u32 n = count[0] & 0x3f;
    count[1] = s->count[1];
    int k;
    if (n < 0x38) k = 0x38 - n;
    else k = 0x78 - n;
    func_00547200(s, D_0064C340, k);
    u32 carry = count[0] >> 29;
    count[0] <<= 3;
    count[1] = (count[1] << 3) + carry;
    func_006C82E0(bits, count, 8);
    func_00547200(s, bits, 8);
    func_006C82E0(out, s, 0x10);
    func_005A48D8(s, 0, 0x60);
}
