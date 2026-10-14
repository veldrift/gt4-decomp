/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern u16 D_006B9980[];
extern u16 D_006B9998[];
extern u16 D_006B99B0[];

extern "C" {
int func_004C5208(const u16 *, u8 *) throw();
void func_004C8F08(u16 *, u16 *);
}

extern "C" void func_004C55D8(u16 *out, u16 *in, int n, int kind, u32 cap)
{
    u16 buf[40];
    u8 len;
    int j = 0;
    int i;
    u16 *tbl;

    if (kind == 0xD) {
        tbl = D_006B9980;
    } else {
        tbl = D_006B9998;
    }
    i = 0;
    if (n > 0) {
        do {
            u16 *s = in + i;
            int c = func_004C5208(s, &len);
            if (c > 0) {
                if ((u32)c < 10) {
                    buf[j] = tbl[c];
                } else {
                    switch (c) {
                    case 0x65:
                        buf[j] = tbl[10];
                        break;
                    case 0x66:
                        buf[j] = D_006B99B0[0];
                        break;
                    case 0x67:
                    case 0x68:
                        buf[j] = D_006B99B0[1];
                        break;
                    case 0x3EC:
                        buf[j] = D_006B99B0[2];
                        break;
                    case 0x3F0:
                        buf[j] = D_006B99B0[3];
                        break;
                    case 0x3F4:
                        buf[j] = D_006B99B0[4];
                        break;
                    }
                }
                j++;
                i += len;
            } else {
                i++;
                buf[j] = *s;
                j++;
            }
        } while (i < n);
    }
    buf[j] = 0;
    if (cap < (u32)(j * 2 + 2)) {
        *out = 0;
        return;
    }
    func_004C8F08(out, buf);
}
