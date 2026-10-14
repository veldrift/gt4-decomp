struct Buf { int d[91]; };
struct Obj { int pad; Buf buf[2]; int cur; int flag; };
extern "C" void func_0045A7D8(Obj *o, Buf *src)
{
    o->cur ^= 1;
    o->buf[o->cur] = *src;
    if (o->flag == 0) {
        o->flag = 1;
        o->buf[1 - o->cur] = o->buf[o->cur];
    }
}
