typedef unsigned int u32;
struct Stream { char pad[8]; unsigned used; char padC[4]; char *data; };
struct Rec { unsigned char state,b1,b2,b3,b4,b5; char pad6[6]; int slot; char *base,*end,*cursor; int f1c,timer,f24,stamp; Stream stream; };
struct Msg { unsigned char id,b1,b2,b3,b4,b5; unsigned short capacity,f8,length; char data[1]; };
struct Range { char pad[16]; u32 start,count; };
struct Global { char pad[0xA578]; void (*cb[256])(int,unsigned,const char *,unsigned); };
struct Clock { char pad[0x5c]; int tick; };
extern Global *D_0064B4B4;
extern Clock *D_0064B47C;
extern "C" Rec *func_00515EE8(unsigned) throw();
extern "C" int func_00515F98(int *,void *) throw();
extern "C" Range *func_0051B8A8(void *,unsigned);
extern "C" char *func_005316F8(unsigned);
extern "C" void func_00531738(char **);
extern "C" int func_00537FC8(Stream *,unsigned,char *);
extern "C" int func_005380D8(Stream *,int);
extern "C" int func_00538228(Stream *,const char *,unsigned);
extern "C" int func_00538418(Stream *,int);
extern "C" int func_005385B0(Stream *,unsigned *);
extern "C" void *func_005A4724(void *,const void *,unsigned);
static inline char *end(char *base,unsigned n) { return base + n; }
extern "C" int func_0051A9D8(void *self,int unused,int slot,Msg *m) {
    int selected = 256;
    if (!self) return -1;
    Rec *r = func_00515EE8(m->id);
    if (!r) return m->length + 12;
    if (r->state != 2) {
        if (m->b4) {
            r->base = func_005316F8(m->capacity);
            if (!r->base) { r->state = 0; return m->length + 12; }
            if (func_00537FC8(&r->stream,m->capacity,r->base)) {
                func_00531738(&r->base);
                return m->length + 12;
            }
            r->end = end(r->base,m->capacity);
            r->b3 = m->b2;
            r->b5 = m->b1;
            r->cursor = r->base;
            r->f1c = 0;
            r->b1 = m->b3;
            r->b2 = m->b4;
            r->timer = 90000;
            r->b4 = 0;
            r->stamp = 0;
        }
        r->state = 2;
        func_00515F98(&selected,self);
        if (slot != selected) r->slot = slot;
        else {
            for (int i = 0; i < 64; ++i) {
                Range *range = func_0051B8A8(self,i);
                if (!range) continue;
                if ((u32)(m->id-range->start) >= range->count) continue;
                r->slot = i;
                break;
            }
        }
    }
    char *data = m->data;
    if (m->b4) {
        Stream *stream = &r->stream;
        unsigned available = 0;
        if (!func_005385B0(stream,&available)) {
            if (m->b3) {
                if (!func_005380D8(stream,m->length-available)) {
                    func_00538228(stream,data,m->length);
                    func_00538418(stream,1);
                    func_005A4724(r->base,r->stream.data,r->stream.used);
                }
            } else if (available) {
                available = m->length < available ? m->length : available;
                func_00538228(stream,data,available);
                func_005A4724(r->base,r->stream.data,r->stream.used);
            }
        }
    }
    void (*cb)(int,unsigned,const char *,unsigned) = D_0064B4B4->cb[m->b2];
    if (cb) cb(slot,m->id,data,m->length);
    r->stamp = D_0064B47C->tick;
    return m->length + 12;
}
