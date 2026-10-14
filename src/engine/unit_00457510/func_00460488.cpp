struct Node {
    int f0;
    int f4;
    int link;
    unsigned int count;
    char pad[0x14 - 0x10];
};
extern "C" void func_004603F8(void *arg0, int arg1, int arg2);

extern "C" void func_00460488(Node *arg0, void (*arg1)(void *), int arg2) {
    unsigned int n;
    int diff;
    long d;
    char *p;
    void *cur;
    n = 0;
    diff = (int)arg0 - arg0->link;
    arg0->link = (int)arg0;
    if (arg0->count != 0) {
        d = diff;
        p = (char *)arg0 + 0x14;
        do {
            func_004603F8(p, d, arg2);
            cur = p;
            p += 8;
            if (arg1 != 0) {
                arg1(cur);
            }
            n += 1;
        } while (n < arg0->count);
    }
}
