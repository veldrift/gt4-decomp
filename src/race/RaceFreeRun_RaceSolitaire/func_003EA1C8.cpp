/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00359CC8(int, int, int);
extern "C" void *RaceSolitaire__getInputGhost(void *);
extern "C" void func_003EA1C8(char *self, int n) {
    char *p = *(char **)(self + 0x6c);
    *(int *)(p + 0xb0) = 0;
    *(int *)(p + 0xe8) = 0;
    int x = *(int *)(self + 0x70);
    func_00359CC8(x, 0, n);
    if (*(int *)((char *)RaceSolitaire__getInputGhost(self) + 0x1d0) == 0)
        func_00359CC8(x, 1, n);
}
