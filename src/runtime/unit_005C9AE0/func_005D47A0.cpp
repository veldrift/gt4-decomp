typedef int s32;

/* 44-byte record (0x2C): 40 bytes of payload, then the 4-byte sort key at +0x28. */
struct Rec44 {
    char b[40];
    s32 key;
};

extern "C" void func_005D47A0(char *arg0, char *arg1) {
    Rec44 tmp = *(Rec44 *)arg1;
    Rec44 *tp = &tmp;
    Rec44 *hole = (Rec44 *)arg0;
    Rec44 *prev = (Rec44 *)(arg0 - 0x2C);

    while (tp->key < prev->key) {
        *hole = *prev;
        hole = prev;
        prev = (Rec44 *)((char *)prev - 0x2C);
    }
    *hole = *tp;
}
