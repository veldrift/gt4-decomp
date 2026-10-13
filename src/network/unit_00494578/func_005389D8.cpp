extern "C" unsigned int func_005389D8(signed char *p) {
    unsigned int acc = 0;
    unsigned int cur = 0;
    if (p != 0) {
        int c = *p;
        p++;
        if (c != 0) {
            do {
                int d = c - 0x30;
                if (c == 0x2E) {
                    unsigned int hi = cur << 24;
                    cur = 0;
                    acc = (acc >> 8) + hi;
                } else {
                    if ((unsigned char)d < 10) {
                        cur = cur << 1;
                        cur += cur << 2;
                        cur += d;
                    }
                }
                c = *p;
                p++;
            } while (c != 0);
        }
        acc = (acc >> 8) + (cur << 24);
    }
    return acc;
}
