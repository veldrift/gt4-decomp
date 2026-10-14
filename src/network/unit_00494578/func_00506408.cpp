struct Header { char bytes[0x64]; };
struct Obj { Header header; int a, b, c; short d, e, f, g, h; };
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_00506408(Obj *dst, Header *src) {
    func_005A48D8(dst, 0, 0x64);
    dst->header = *src;
    dst->header.bytes[0x63] = 0;
    dst->a = 2;
    dst->b = 1;
    dst->c = 0x400;
    dst->d = 0xa;
    dst->e = 0x64;
    dst->f = 0xa;
    dst->g = 0x28;
    dst->h = 0;
    return 0;
}
