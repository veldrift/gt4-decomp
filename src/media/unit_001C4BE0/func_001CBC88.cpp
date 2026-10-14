/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001CBC88(signed char *p) {
    for (;;) {
        int c = p[0];
        if (!c) return;
        if (c & 0x80) {
            signed char d = p[1];
            if (!d) return;
            int v = (c << 8) | (d & 0xFF);
            int lo = v & 0x7F;
            c = (((v & 0x7F00) + 0x2100) >> 1) ^ 0xA000;
            if (!(v & 0x100)) c -= 2;
            else c = c + 0x20 - (lo < 0x60);
            c += lo;
            p[1] = c;
            p[0] = c >> 8;
            p += 2;
        } else {
            ++p;
        }
    }
}
