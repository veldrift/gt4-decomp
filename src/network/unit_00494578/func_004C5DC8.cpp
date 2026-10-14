/* compiler: ee-gcc2.96-no-strict-aliasing */
struct N {
    char data[0x1C];
    N *next;
};
extern "C" void func_004C4070(char *, N *, int) throw();
extern "C" int func_004C5EC0(int, int, int, N **);
extern "C" void func_004C8B50(int, N *);
extern "C" char *func_004C8C20(int, int);

extern "C" int func_004C5DC8(int a0, int a1, int a2, char **out) {
    N *head = 0;
    int n = func_004C5EC0(a0, a1, a2, &head);
    if (n >= 0) {
        N *p = head;
        n = 0;
        if (p != 0) {
            do {
                p = p->next;
                n++;
            } while (p != 0);
        }
        char *buf = func_004C8C20(a0, n * 0x1C);
        *out = buf;
        if (buf == 0) {
            func_004C8B50(a0, head);
            return 0x8000030A;
        }
        char *dst = buf;
        p = head;
        if (p != 0) {
            do {
                func_004C4070(dst, p, 0x1C);
                dst += 0x1C;
                p = p->next;
            } while (p != 0);
        }
    }
    func_004C8B50(a0, head);
    return n;
}
