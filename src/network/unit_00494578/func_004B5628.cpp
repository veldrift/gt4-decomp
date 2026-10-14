/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Entry { signed char type; unsigned char b; short c; short start; short end; };
struct Block { int state; int kind; char pad[0x20c]; int count; Entry entries[64]; int pending; };
struct Self { char p0[12]; int limit; int active; short *out; char p18[8]; Block blocks[2]; int current; };
extern "C" int func_004B4BA8(Self *) throw();
extern "C" void func_004B54E8(Self *) throw();
extern "C" int func_004B4220() throw();
extern "C" int func_004B4B40(Self *,int) throw();
extern "C" void func_004B4CA0(Self *,void *,int) throw();
extern "C" int func_004B55B8(Self *,int) throw();
extern "C" int func_004B4208(int,int) throw();
extern "C" void func_004B42E0(void *,int) throw();
extern "C" void func_004B5B38(Self *,Entry *);
extern "C" void func_0057D9C0(const char *,...);
extern char D_006B0458[];
static inline bool isType(Entry *e, int type) {return e->type==type;}
extern "C" void func_004B5628(Self *self) {
    char buf[0x200];
    char *base=(char *)self+(1-self->current)*0x41c;
    Block *b=(Block *)(base+0x20);
    int *count=(int *)(base+0x234);
    if (func_004B4BA8(self) >= self->limit) {
        int state = b->state;
        if (state == 2) {
            func_004B54E8(self);
            int err = func_004B4220();
            if (err < 0) func_0057D9C0(D_006B0458,err&255,err&0x7f00);
            b->state = 1;
            state = 1;
        }
        if (state != 1) return;
        if (func_004B4B40(self,1) > 0) {
            for (int rounds=0;rounds<2;rounds++) {
                for (int i=0;i<b->count;i++) {
                    Entry *e = &b->entries[i];
                    if(e->type==1) { func_004B5B38(self,e); break; }
                }
            }
        }
        b->pending = 0;
        *self->out=0;
        self->active=0;
    } else {
        func_004B4CA0(self,buf,0x100);
        if (func_004B55B8(self,2) || func_004B55B8(self,3) || func_004B55B8(self,4) || func_004B55B8(self,5)) {
            for (int rounds=0;rounds<2;rounds++) {
                for (int i=1;i<*count-1;i++) {
                    Entry *e = &b->entries[i];
                    if (e->type==1) {func_004B5B38(self,e); break;}
                }
            }
        }
        int n=0;
        for (int i=1;i<*count-1;i++) {
            Entry *e=&b->entries[i];
            if(isType(e,2) || isType(e,3) || isType(e,4) || isType(e,5)) n++;
        }
        if(n>0) {
            int err=func_004B4208(0,n);
            if(err<0) func_0057D9C0(D_006B0458,err&255,err&0x7f00);
        }
        int total=0;
        for(int i=1;i<*count-1;i++) { Entry *e=&b->entries[i]; total += e->end-e->start; }
        Entry *first = &b->entries[0];
        Entry *last = &b->entries[*count-1];
        Entry *dst = &b->entries[1];
        dst->type=last->type;
        dst->b=last->b;
        dst->c=last->c;
        dst->start=last->start;
        dst->end=last->end;
        *count=2;
        b->pending=0;
        first->end += total;
        if(first->end < first->start) first->end=first->start;
        int err=func_004B4220();
        if(err<0) func_0057D9C0(D_006B0458,err&255,err&0x7f00);
        if(b->kind==1) func_004B42E0(buf,0);
        else if(b->kind==2) func_004B42E0(buf,1);
        *self->out=0;
        self->active=0;
    }
}
