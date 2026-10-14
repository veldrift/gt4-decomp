/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" signed char *func_00548D58(signed char *) throw();
extern "C" signed char *func_00548DA0(signed char *p) {
    p = func_00548D58(p);
    for (; *p && *p != '/' && *p != '\\'; ++p) {}
    return p;
}
