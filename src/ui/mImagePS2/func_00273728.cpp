/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Bits { char pad[0x20]; unsigned long data; };
struct Src { char pad[0x18]; Bits *bits; };
struct Dst { char pad[8]; int w, h, unk10; Src *src; float x, y; int z; };
extern "C" float func_002736B0(int) throw();
extern "C" int func_00498B28(void *);
extern "C" void func_00273728(Dst *dst, Src *src, int z) {
    func_00498B28(src);
    int w = ((src->bits->data >> 14) & 0x3FF) + 1;
    dst->w = w;
    dst->h = ((src->bits->data >> 34) & 0x3FF) + 1;
    dst->x = func_002736B0(w);
    float y = func_002736B0(dst->h);
    dst->src = src;
    dst->z = z;
    dst->y = y;
}
