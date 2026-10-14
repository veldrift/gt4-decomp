/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int x[11]; int ptr; int tail[5]; };
struct Course { int unk0; void *data; };
struct Obj { int head[2]; Block items[8]; char pad[0x260]; Course *course; };
struct Runway { char pad[0x84]; int base; };
extern "C" Runway *CourseData__getRunway(void *);
extern "C" int func_0045D0D8(void);
extern "C" char *func_0045CDC8(Obj *self, char *out) {
    ((int *)out)[1] = func_0045D0D8();
    ((int *)out)[0] = 0;
    out += 8;
    Block *dst = (Block *)out;
    int n;
    int off = 0;
    for (n = 0; n < 8; n++) {
        *dst = *(Block *)(off + (int)self + 8);
        off += 0x44;
        dst->ptr = (dst->ptr - CourseData__getRunway(self->course->data)->base) >> 4;
        dst++;
    }
    return out + 0x220;
}
