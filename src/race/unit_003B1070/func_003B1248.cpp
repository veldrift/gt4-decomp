typedef int s32;

struct Item3B1248 {
    char pad[0x40];
    s32 idx;
};

extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A74B4(void *arg0);
extern "C" void func_004A7550(void *arg0);
extern "C" void func_004A7698(void *arg0);

extern "C" void func_003B1248(char *arg0, char *arg1, void *arg2) {
    s32 n;
    Item3B1248 **pp;
    s32 off;

    func_004A53F8();
    func_004A74B4(arg2);
    pp = (Item3B1248 **)(arg0 + 0x764);
    n = 0x13;
    do {
        if (*pp != 0) {
            off = (*pp)->idx;
            func_004A53F8();
            off = off << 6;
            func_004A7698(arg1 + off);
            func_004A7698(*pp);
            func_004A7550(arg1 + off);
            func_004A5400();
        }
        n--;
        pp++;
    } while (n >= 0);
    func_004A5400();
}
