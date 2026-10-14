typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_004BC868(u8 *arg0, const u16 *arg1, int arg2) {
    if (arg2 > 0) {
        do {
            u16 v = *arg1++;
            *arg0++ = v >> 8;
            *arg0++ = v;
            arg2--;
        } while (arg2 > 0);
        arg0++;
    }
}
