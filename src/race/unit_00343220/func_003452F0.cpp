/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00345218(void *) throw();
extern "C" int func_00463C28(void *, int, int);
struct E { char pad[0x464]; unsigned int flags; };
extern "C" int func_003452F0(char *self) {
    int flag = 0;
    E *e = (E *)(self + 0x104);
    if (*(signed char *)((char *)e + 0x466) == 4) return 0;
    int state = *(unsigned char *)((char *)e + 0x467);
    if (state == 2 || state == 4 || state == 3) flag = 1;
    if (!(e->flags & 0xFFFF0000)) flag = 1;
    if (flag) {
        if (func_00345218(self)) func_00463C28(self + 0x14, 6, 1);
    }
    *(unsigned char *)((char *)e + 0x467) = 1;
    return 1;
}
