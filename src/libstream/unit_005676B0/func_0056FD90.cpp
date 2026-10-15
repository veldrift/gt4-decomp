/* compiler: ee-gcc2.96-nsa-nosib */
extern "C" int func_0056FC78(int, int, int *, int);
extern "C" int func_0056FC90();
extern "C" int func_0056FD70(int, int, int, int);
extern "C" int func_0056FD90(int arg0, int arg1, int *arg2, int arg3, int arg4) {
    int r = func_0056FC90();
    if (r < 0) {
        r = func_0056FC78(arg0, arg1, arg2, arg3);
        if (r < 0) return r;
    }
    r = func_0056FD70(arg0, arg1, *arg2, arg4);
    if (r >= 0) r = 0;
    return r;
}
