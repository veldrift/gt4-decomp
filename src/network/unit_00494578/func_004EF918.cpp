/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0x7C]; void *b; };
extern "C" int func_0056ECF8(void *, void *, int, int, const char *, int, int, ...);
extern "C" int func_004EF918(Self *s, int flag, int id, const char *name, int x, int y, ...) {
    char *volatile ap;
    int extra = 0;
    if (flag & 0x80) {
        ap = (char *)__builtin_next_arg(y) - ((8 - __builtin_args_info(2)) * 8);
        extra = *(int *)ap;
        ap += 8;
    }
    return func_0056ECF8((char *)s + 4, s->b, flag, id, name, x, y, extra);
}
