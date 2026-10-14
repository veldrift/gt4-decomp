/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Context { char pad[0x18]; char *car; };
extern "C" int func_00354E38(void *);
extern "C" int func_00354E68(void *);
extern "C" int GetPitStopStatus(void *);
extern "C" int func_0035FC80(void *);
extern "C" int func_003F4EA0(void *);
extern "C" int func_003DA6F8(void *, Context *ctx) {
    int result = 0;
    char *p = ctx->car;
    if (GetPitStopStatus(p) == 0) {
        int count = func_0035FC80(p);
        if (func_00354E38(p) && func_00354E68(p)) {
            result = 2;
        } else {
            p += 0x7B8;
            int valid = 1;
            int i = 0;
            if (count > 0) {
                result = 4;
            } else {
                do {
                    if (func_003F4EA0(p) == 0) valid = 0;
                    p += 0x34;
                    i++;
                    if (!valid) goto done;
                } while (i < 4);
                result = 5;
            }
        }
    } else {
        result = 3;
    }
done:
    return result;
}
