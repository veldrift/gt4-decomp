/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
static inline char *copy(Rep *r) {
    char *d = (char *)(r + 1);
    if (r->sel) d = func_005C2560(r);
    else { int n = r->ref + 1; r->ref = n; }
    return d;
}
struct Str { char *p; Str() { p = copy(&D_00659FA8); } };
struct RefCounter {
    int f0;
    RefCounter() __asm__("func_00328420");
    virtual ~RefCounter();
};
struct mLocalizedText : RefCounter {
    Str a, b;
    mLocalizedText() __asm__("func_002B6F00");
    virtual ~mLocalizedText();
};
mLocalizedText::mLocalizedText() : RefCounter(), a(), b() {}
