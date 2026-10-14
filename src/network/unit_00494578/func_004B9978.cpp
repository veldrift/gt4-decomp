/* compiler: ee-gcc2.96-no-strict-aliasing */
struct CodeTable;
extern CodeTable D_006B0D80;
extern CodeTable D_006B10F8;
extern "C" unsigned short func_004B94A8(CodeTable *, int) throw();
extern "C" unsigned short *func_004B9978(unsigned short *out, int size, unsigned char *src) {
    int n = 0;
    unsigned short *p = out;
    int c = *src++;
    while (c != 0) {
        int room = n < size;
        n++;
        if (!room) return out;
        if (c >= 32) {
            if (c < 128) {
                c = func_004B94A8(&D_006B0D80, c);
            } else {
                int next = *src++;
                int code = ((c & 127) << 8) | (next & 127);
                if (next == 0) src--;
                c = func_004B94A8(&D_006B10F8, code);
            }
        }
        if (c == 0) c = '?';
        *p++ = c;
        c = *src++;
    }
    *p = 0;
    return out;
}
