/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State {
    char pad[0x498]; u8 count; char pad499[7];
    int entries[42]; u16 index; char pad54a[2]; char *cache; u16 used; u16 data[58];
};
struct Context { char pad[0x2c]; int *type; State *state; };
extern "C" Context *D_006452D4;
extern "C" int func_004BAA70(int, int, char *, int);
extern "C" void func_004BC740(char *, char *);
extern "C" int func_004C8718(Context *, u16 *, int, u16 *, char *);
extern "C" void func_004C8C38(Context *, int);
extern "C" void func_004C90F0(char *, u16 *);
extern "C" int func_004C9410(char *);
extern "C" int func_004BA700(int index, char *buffer, int size, u8 separator) {
    struct { char text[0x80]; u16 wide[0x40];  } stack;
    char *original = buffer;
    int sep = separator;
    if ((u32)(size-1) >= 0x7fff) return 0x80001547;
    if (!original) return 0x80001647;
    if (index < 0) return 0x80001947;
    if (*D_006452D4->type != 0x65) return 0x80000147;
    if (index >= D_006452D4->state->count) return 0x80001347;
    if (!sep) return 0x80001247;
    char *cursor = original;
    int left = size;
    int status = func_004BAA70(index, 0, cursor, left);
    if (status <= 0) {
        index = (u16)(D_006452D4->state->count-index-1);
        if (D_006452D4->state->index != 0x7fff) {
            int p = (int)D_006452D4->state->cache;
            if (p) {
                func_004C8C38(D_006452D4, p);
                D_006452D4->state->cache = 0;
                D_006452D4->state->index = 0x7fff;
            }
        }
        int offset = index * 4 + 0x4a0;
        D_006452D4->state->used = 0;
        int p = *(int *)((char *)D_006452D4->state+offset);
        if (p) {
            func_004C8C38(D_006452D4, p);
            *(int *)((char *)D_006452D4->state+offset) = 0;
        }
        return status;
    }
    int i = 1;
    cursor += status;
    left -= status;
    if (i < D_006452D4->state->used) {
        u16 *wide = stack.wide;
        int offset = 0x4a4;
        int cacheOffset = 0x1c;
        do {
            Context *ctx = D_006452D4;
            State *st = ctx->state;
            char *cache = st->cache + cacheOffset;
            cacheOffset += 0x1c;
            if (func_004C8718(ctx, wide, 0x74, st->data, cache) < 0) {
                *original = 0;
                int p = (int)D_006452D4->state->cache;
                if (p) {
                    func_004C8C38(D_006452D4, p);
                    D_006452D4->state->cache = 0;
                }
                D_006452D4->state->index = 0x7fff;
                D_006452D4->state->used = 0;
                p = *(int *)((char *)D_006452D4->state+offset);
                if (p) {
                    func_004C8C38(D_006452D4, p);
                    *(int *)((char *)D_006452D4->state+offset) = 0;
                }
                return 0x80004747;
            }
            func_004C90F0(stack.text, wide);
            index = func_004C9410(stack.text) + 1;
            if (left >= index) {
                left -= index;
                status = 0;
                func_004BC740(cursor, stack.text);
                cursor[-1] = sep;
                cursor += index;
            } else {
                left -= index;
                status = -1;
                break;
            }
            i++;
            offset += 4;
        } while (i < D_006452D4->state->used);
    }
    if (status < 0) {
        State *st = D_006452D4->state;
        st->used = i;
        char *base = (char *)D_006452D4->state;
        index = st->index & 0x7fff;
        int offset = index*4+0x4a0;
        int p = *(int *)(base+offset);
        if (p) {
            func_004C8C38(D_006452D4, p);
            *(int *)((char *)D_006452D4->state+offset) = 0;
        }
        D_006452D4->state->index = index | 0x8000;
        return 0x80001047;
    }
    return i;
}
