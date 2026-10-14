struct Buffer { unsigned pos,write,end,total; char *data; };
extern "C" int func_00538530(Buffer *, unsigned *);
extern "C" int func_00538558(Buffer *, unsigned *);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern "C" int func_00538338(char *dst,Buffer *s,unsigned size) {
    unsigned avail=0;
    unsigned tail=0;
    int result=2;
    if (dst && s && size) {
        int r = func_00538530(s, &avail);
        if (r) return r;
        if (avail >= size) {
            r = func_00538558(s, &tail);
            if (r) return r;
            if (tail >= size) {
                func_005A4724(dst, s->data + s->pos, size);
            } else {
                func_005A4724(dst, s->data + s->pos, tail);
                func_005A4724(dst + tail, s->data, size - tail);
            }
            result = 0;
        } else result = 200;
    }
    return result;
}
