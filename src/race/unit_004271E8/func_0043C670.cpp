struct T { char d[8]; signed char x; signed char y; signed char z; };
struct D { char pad[0x10]; T t; };
extern "C" char *func_0043C670(D *dst, T *src) {
    dst->t = *src;
    return (char *)src + 0xC;
}
