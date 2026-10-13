/* mTextBoxFace__structor_0: constructor body. Base constructor func_002D4830 (returns
 * this), vtable store at +4, a 16-byte local array passed to func_002270F8, func_00246F58
 * on the member at +0xC0, a 0x80-iteration loop filling the pointer table at +0x12C from the
 * nil string rep D_00659FA8 (grab: clone when selfish, else ref++ and data pointer), then
 * the flag/int stores and the final call to func_00265FB8. */
typedef int s32;

struct StringRep;
extern "C" void *func_002D4830(void *self);
extern "C" void func_002270F8(void *a, s32 *buf);
extern "C" void func_00246F58(void *self);
extern "C" void func_00265FB8(void *self, s32 arg1);
extern "C" char *func_005C2560(StringRep *src);
extern char D_00659FA8[];
extern char D_006725E8[];

extern "C" void func_002E4D60(void *arg0) {
    char *self = (char *)arg0;
    char **w = (char **)(self + 0x12C);
    s32 n = 0x7F;
    char *s4 = self + 0xC0;
    s32 neg1 = -1;
    s32 buf[4];
    char *s1;
    char *v;

    func_002D4830(arg0);
    *(s32 *)(self + 4) = (s32)D_006725E8;
    buf[0] = 0;
    func_002270F8(self + 0xBC, buf);
    func_00246F58(s4);
    *(s32 *)(self + 0x124) = 0;
    *(s32 *)(self + 0x128) = 0;
    s1 = D_00659FA8;

    do {
        if (*(s32 *)(s1 + 0xC) != 0) {
            v = func_005C2560((StringRep *)s1);
        } else {
            v = s1 + 0x10;
            *(s32 *)(s1 + 8) = *(s32 *)(s1 + 8) + 1;
        }
        n = n - 1;
        *w = v;
        w++;
    } while (n != neg1);

    *(s32 *)(self + 0x3AC) = 0;
    *(s32 *)(self + 0x3B8) = 1;
    *(s32 *)(self + 0x3B0) = 0;
    *(s32 *)(self + 0x3B4) = 0;
    *(s32 *)(self + 0x3BC) = 0;
    *(s32 *)(self + 0x3C0) = 0;
    *(s32 *)(self + 0x3C4) = 0;
    *(s32 *)(s4 + 0x18) = 1;
    *(s32 *)(s4 + 0x24) = 0;
    *(s32 *)(s4 + 0x20) = 0;
    *(s32 *)(self + 0xB0) = 1;
    func_00265FB8(arg0, 1);
}
