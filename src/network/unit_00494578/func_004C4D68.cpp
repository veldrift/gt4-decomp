/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C4CB8(unsigned short) throw();
extern "C" void func_004C4D68(unsigned short *dst, unsigned short *src, int n) {
    int count = n - 1;
    if (n != 0) {
        do {
            if ((unsigned int)(func_004C4CB8(*src) - 2) < 0x53)
                *dst = *src + 0x100;
            else
                *dst = *src;
            --count;
            ++dst;
            ++src;
        } while (count != -1);
    }
}
