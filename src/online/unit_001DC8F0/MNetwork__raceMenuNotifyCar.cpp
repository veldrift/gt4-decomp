typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
extern "C" void func_001DC650(void *, void *) throw();
extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" void func_00312370(void *, void *);
extern "C" void func_00312318(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" char **func_00314920(s32);
extern "C" void func_001F6EF0(s32, const char *, s32);
extern char D_006959D8[];
static inline const char *c_str(char **slot) {
    char *text = *slot;
    s32 length = ((Rep *)text - 1)->len;
    if (length == 0) return D_006959D8;
    text[length] = 0;
    return *slot;
}
extern "C" void MNetwork__raceMenuNotifyCar(void *self, void *arg1, s32 count, char *arg3) {
    if (count < 2) return;
    s32 current[4], code[4], value[4];
    func_001DC650(current, arg1);
    s32 *pCode = code;
    func_00312370(pCode, arg3);
    s32 *pValue = value;
    func_002FC8C8(pValue, arg3 + 4);
    s32 selected = current[0];
    char **slot = func_00314920(*pCode);
    const char *result = c_str(slot);
    func_001F6EF0(selected, result, func_002FE250(*pValue));
    func_002FC870(pValue, 2);
    func_00312318(pCode, 2);
    func_001DC5F8(current, 2);
}
