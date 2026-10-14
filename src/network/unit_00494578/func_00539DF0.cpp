typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct St { int pad; u32 end, cur; int pad2, err; };
extern "C" void func_00539DF0(int mode, St *s, u16 *val) {
    if (s->err == 0) {
        u32 end = s->end;
        u32 cur = s->cur;
        if (!(cur < end) || cur == 0) { s->err=2; return; }
        if (end-cur < 4) { s->err=8; return; }
        {
            u16 v=*val;
            if (v >= 0x7fff) { s->err=2; return; }
            if (mode==1) {
                if (v>=0x80) {
                    *(u8 *)cur=(v>>8)|0x80;
                    cur=s->cur+1;
                    s->cur=cur;
                }
                *(u8 *)cur=*(u8 *)val;
                cur=s->cur;
                s->cur=cur+1;
            } else if (mode==2) {
                u8 b=*(u8 *)cur;
                *val=b;
                if (b&0x80) {
                    *val <<= 8;
                    u32 next=cur+1;
                    s->cur=next;
                    *val &= 0x7fff;
                    *val |= *(u8 *)next;
                }
                if (*val >= 0x7fff) {s->err=mode; return;}
                cur=s->cur;
                s->cur=cur+1;
            } else { s->cur=cur+1; }
        }
        return;
    }
}
