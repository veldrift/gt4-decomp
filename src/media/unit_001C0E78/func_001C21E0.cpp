/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

struct P { f32 x, y; u32 n; s32 zeros; u32 b; u32 c; s32 *out; };
struct Img { char pad0[8]; s32 stride; char padC[8]; u8 *data; };

extern "C" void func_001C21E0(P *p, Img *img, f32 a, f32 b) {
    u32 i, cnt, cnt2;
    s32 sum, zeros, col, rowoff;
    u8 *d;
    p->x = a;
    i = 0;
    p->y = b;
    sum = 0;
    zeros = 0;
    col = 0;
    rowoff = 0;
    do {
        d = img->data;
        sum += d[col + rowoff];
        { s32 o = col; for (u32 k = i; k != 0; k--) { sum += img->data[o]; o += img->stride; } }
        { s32 o = rowoff; for (u32 k = i; k != 0; k--) { sum += img->data[o]; o++; } }
        if (sum == 0) zeros++;
        p->out[i] = sum;
        i++;
        col++;
        rowoff += img->stride;
    } while (i < p->n);
    cnt = p->b;
    p->zeros = zeros;
    if (cnt != 0) {
        do {
            s32 o = col;
            for (u32 k = p->n; k != 0; k--) {
                sum += img->data[o];
                o += img->stride;
            }
            col++;
            p->out[i] = sum;
            i++;
        } while (--cnt != 0);
    }
    cnt2 = p->c;
    if (cnt2 != 0) {
        do {
            s32 o = rowoff;
            for (u32 k = p->n; k != 0; k--) {
                sum += img->data[o];
                o++;
            }
            p->out[i] = sum;
            i++;
            rowoff += img->stride;
        } while (--cnt2 != 0);
    }
    p->out[i] = sum;
}
