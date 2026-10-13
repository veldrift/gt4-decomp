typedef unsigned short u16;

extern "C" void func_004C8F08(u16 *arg0, u16 *arg1) {
    u16 *start = arg1;

    {
        u16 c;
        do {
            c = *arg1;
            arg1++;
        } while (c != 0);
    }

    arg1 -= 2;

    if (!(arg1 < start)) {
        int stop;
        do {
            u16 c = *arg1;
            arg1--;
            stop = arg1 < start;
            *arg0 = c;
            arg0++;
        } while (!stop);
    }

    *arg0 = 0;
}
