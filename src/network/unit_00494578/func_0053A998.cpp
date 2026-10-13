int func_0053A860(void *);                      /* extern */
int func_0053A890(void *, unsigned int *);      /* extern */

int func_0053A998(unsigned int arg0) {
    int buf[4];
    unsigned int n;
    int r;

    n = 0;
    r = func_0053A860(buf);
    goto test;
    do {
        r = func_0053A890(buf, &n);
    test:
        if (r != 0) {
            return r;
        }
    } while (n < arg0);
    return 0;
}
