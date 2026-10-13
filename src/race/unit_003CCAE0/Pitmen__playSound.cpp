extern "C" void func_003934A0(void *a, void *b, void *c, float x, float y);

extern "C" void func_003D3358(char *arg0)
{
    int i = 0;
    int *p = (int *)(0x98B8 + arg0);

    while (i < 6) {
        int v;
        i++;
        v = *p;
        p += 2;
        if (v == 0) {
            continue;
        }
        func_003934A0(arg0 + 0x98E8, (void *)0x46, (void *)0x40, 1.0f, 1.0f);
        break;
    }
}
