typedef unsigned short u16;

extern "C" u16 *func_004C8C50(u16 *arg0, u16 *arg1) {
    u16 *dst = arg0;
    u16 *src = arg1;

    while (*dst++ != 0)
        ;
    dst--;

    while ((*dst++ = *src++) != 0)
        ;

    return arg0;
}
