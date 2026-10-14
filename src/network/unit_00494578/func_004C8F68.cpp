/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern "C" void func_004C8F68(u16 *arg0, u16 *arg1, int n) {
    u16 *start = arg1;
    u16 c;
    do {
        c = *arg1;
        arg1++;
    } while (c != 0);
    arg1--;
    if (n > 0) {
        arg1--;
        if (!(arg1 < start)) {
            int stop;
            do {
                u16 c = *arg1;
                arg1--;
                n--;
                stop = arg1 < start;
                *arg0 = c;
                arg0++;
            } while (n > 0 && !stop);
        }
    }
    *arg0 = 0;
}
