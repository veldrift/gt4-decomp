/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Table {
    char p[0x134];
    void *items[43];
};
extern "C" int SPEC_DATABASE__DatabaseTable__searchNumber(void *, u32);
extern "C" int SPEC_DATABASE__DatabaseStorage__IsExistID_2(Table *t, u32 a1, u32 idx)
{
    if (idx >= 0x2B) return 0;
    void *p = t->items[idx];
    if (p == 0) return 0;
    return SPEC_DATABASE__DatabaseTable__searchNumber(p, a1) != -1;
}
