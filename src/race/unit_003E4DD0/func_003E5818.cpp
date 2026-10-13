typedef int s32;
typedef unsigned short u16;

extern "C" void func_003E6CC0(int *arg0, s32 arg1);
extern "C" void func_003E6CE0(int *arg0, s32 arg1);
extern "C" void func_003E6D00(int *arg0, s32 arg1);

extern "C" void func_003E5818(char *arg0)
{
    s32 s2 = (s32)arg0 - *(s32 *)(arg0 + 0x4);

    if (s2 != 0) {
        *(s32 *)(arg0 + 0x4) = (s32)arg0;

        {
            s32 *h = (s32 *)(arg0 + 0x58);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x5C);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x60);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x64);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x68);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x6C);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x70);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x74);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x78);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x7C);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x80);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x84);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x8C);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x90);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 *h = (s32 *)(arg0 + 0x9C);
            if (*h != 0) {
                *h = *h + s2;
            }
        }

        {
            s32 s1 = 0;

            if (*(u16 *)(arg0 + 0x38) != 0) {
                do {
                    s32 off = (s32)(s1 << 3);
                    s1 += 1;
                    func_003E6CE0((int *)(*(s32 *)(arg0 + 0x58) + off), s2);
                } while (s1 < (s32)*(u16 *)(arg0 + 0x38));
            }
        }

        {
            s32 s1 = 0;

            if (*(u16 *)(arg0 + 0x4A) != 0) {
                do {
                    s32 off = (s32)(s1 << 4);
                    s1 += 1;
                    func_003E6CC0((int *)(*(s32 *)(arg0 + 0x7C) + off), s2);
                } while (s1 < (s32)*(u16 *)(arg0 + 0x4A));
            }
        }

        {
            s32 s1 = 0;

            if (*(u16 *)(arg0 + 0x54) != 0) {
                do {
                    s32 off = (s32)(s1 << 5);
                    s1 += 1;
                    func_003E6D00((int *)(*(s32 *)(arg0 + 0x9C) + off), s2);
                } while (s1 < (s32)*(u16 *)(arg0 + 0x54));
            }
        }
    }
}
