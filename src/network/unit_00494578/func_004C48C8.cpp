/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;
struct Tbl { char pad[0x50]; u8 *data; int len; unsigned short a58, a5a, a5c; u8 a5e; };
struct Obj { u8 *data; int *flag; char pad[0x1c]; Tbl *tbl; };
extern Obj *D_006452D4;
extern "C" void func_004C3F90(u8 *, u32) throw();
extern "C" int func_004BED58(Obj *, int, int) throw();
extern "C" void func_004BFC70(Obj *, int) throw();
extern "C" void func_004C4B98(u32, void *);
static inline int narrow(long n) { return n; }
extern "C" int func_004C48C8(u8 *data, long len) {
    int hi = (data[0] << 24) | data[3];
    int lo = (data[2] << 8) | (data[1] << 16);
    int tag = hi | lo;
    if (tag != 0 && tag != 0xf0000000) return 0x8000445a;
    if (len <= 0x8007) return 0x8000445a;
    if (tag == 0xf0000000) {
        int h = (data[4] << 24) | data[7];
        int l = (data[6] << 8) | (data[5] << 16);
        if ((h | l) != (long)(int)len) return 0x8000445a;
    }
    Obj **g = &D_006452D4;
    (*g)->data = data+8;
    (*g)->tbl->data = (*g)->data;
    (*g)->tbl->a5a = 0x80;
    (*g)->tbl->a5c = 0x190;
    (*g)->tbl->len = narrow(len-8);
    (*g)->tbl->a5e = 3;
    if (tag == 0) {
        int n = narrow(len);
        func_004C3F90(data, n);
        func_004BED58(*g, 2, 0x300);
        *(*g)->flag = 1;
        func_004C4B98(0xf0000000, data);
        func_004C4B98(n, data+4);
        func_004BFC70(*g, 0x300);
    } else {
        func_004BED58(*g, 1, 0x300);
        *(*g)->flag = 1;
    }
    return 0;
}
