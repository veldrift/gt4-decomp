/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { unsigned short text[4]; int length; int value; };
extern Entry D_006B99C0[];
extern "C" int func_004C8DB8(const unsigned short *, const unsigned short *, int);
extern "C" int func_004C5208(const unsigned short *text, unsigned char *length) {
    Entry *p = D_006B99C0;
    while (p->value > 0) {
        int cmp = func_004C8DB8(text, p->text, p->length);
        if (cmp == 0) {
            *length = (unsigned char)p->length;
            return p->value;
        }
        if (cmp > 0) {
            if (*text != p->text[0]) return -1;
        }
        p++;
    }
    return -1;
}
