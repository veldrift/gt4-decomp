/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj { char pad[0x24]; char *data; };
struct Token { u16 value; char pad[0x1e]; };
extern "C" u16 func_004C07F8(void *, int, int, int);
extern "C" int func_004BC978(void *, int, Token *, int) throw();
extern "C" void func_004BDAE8(void *, int, Token *, int, const u8 **, int *) throw();
extern "C" int func_004C92D8(const u8 *, const u8 *, unsigned int);
extern "C" int func_004BD9A8(const u8 *, const u8 *, int, int, int) throw();
extern "C" int func_004BDB48(Obj *, int, const u8 *, int, int, int, u16 *, int *) throw();
static inline int midpoint(int a, int b) { return (a + b) / 2; }
extern "C" int func_004BDD68(Obj *obj, int key, const u8 *input, int length, int mode, u16 *out, int *out2) {
    Token token;
    Token *pt = &token;
    const u8 *data = 0;
    int size = 0;
    int found = 0;
    int low = 1;
    key &= 0xffff;
    *out = 0;
    *out2 = 0;
    int high;
    if ((key & 0xff00) == 0x200) { char *base = obj->data; high = *(u16 *)(base + (key & 0xff) * 16 + 0x48) - 1; }
    else { char *base = obj->data; high = *(u16 *)(base + (key & 0xff) * 16 + 0x58) - 1; }
    int middle = midpoint(high, low);
    if (high > 0) {
        do {
            pt->value = func_004C07F8(obj->data, key, middle, mode);
            if (func_004BC978(obj->data, key, pt, 0) <= 0) return -1;
            func_004BDAE8(obj->data, key, pt, mode, &data, &size);
            int n = length < size ? length : size;
            int cmp;
            if (mode == 0) cmp = func_004C92D8(input, data, n);
            else cmp = func_004BD9A8(input, data, length, size, n);
            if (cmp == 0 && size >= length) {
                high = middle - 1;
                found = 1;
            } else if (cmp < 0) high = middle - 1;
            else low = middle + 1;
            middle = midpoint(high, low);
        } while (high >= low);
    }
    if (found == 0) return 0;
    return func_004BDB48(obj, key, input, length, mode, low, out, out2);
}
