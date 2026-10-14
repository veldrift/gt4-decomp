struct Owner { int unused, active; };
struct Context { int unused, mode, type; char pad[0x7C-12]; Owner *alternate, *normal; };
extern "C" int func_0051BE28(void) throw();
extern "C" int func_0051BE60(void) throw();
extern "C" Context *func_0051DD88(int);
extern "C" int func_0051E158(Owner *, unsigned, int, const void *, unsigned, int);
extern "C" int func_0051C410(int index, int kind, int flags, const void *data, unsigned length) {
    int status = func_0051BE28();
    if (status == 0) {
        int result;
        if (!data || length >= 0x201U) {
            result = 2;
        } else {
            result = 2;
            Context *ctx = func_0051DD88(index);
            if (ctx) {
                result = 0xCB2D;
                if (ctx->type == 8) {
                    Owner *out = ctx->normal;
                    Owner *alternate = ctx->alternate;
                    if (ctx->mode == 1) {
                        if (alternate) {
                            if (alternate->active) out = !(flags & 0x50) ? alternate : out;
                        }
                    }
                    unsigned type = 2;
                    if (kind != 0xFFFE) type = (kind == 0xFFFF) ? 11 : 3;
                    result = func_0051E158(out, type, kind, data, length, (flags >> 7) & 1);
                }
            }
        }
        func_0051BE60();
        status = result;
    }
    return status;
}
