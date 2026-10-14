/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Group { int x, mode; char pad[0x410]; int index; };
struct Obj { char pad[0x20]; Group groups[2]; int active; };
struct Item { unsigned char x,type; unsigned short zero; int word; };
extern char D_006B0458[];
extern "C" {
void func_004B4E50(Obj *) throw();
void func_004B4CA0(Obj *, unsigned short *, int) throw();
int func_004B3FA0(unsigned short *,unsigned short *,int,int);
unsigned short *func_004B48D0(unsigned short *,int,int);
void func_004B47F0(unsigned short *,int) throw();
int func_004B4950(unsigned short *) throw();
void func_004B9438(unsigned short *);
Item *func_004B5A48(Obj *,int,int);
void func_004B5E00(Obj *,Item *,unsigned short *,int);
void func_004B6A38(Obj *);
void func_0057D9C0(const char *,...) throw();
}
static inline int length(unsigned short *p) { int n=0; while(p[n]) ++n; return n; }
extern "C" void func_004B4F28(Obj *self) {
    unsigned short input[256];
    unsigned short buffer[256];
    func_004B4E50(self);
    func_004B4CA0(self,input,256);
    int n=0;
    if (*input) {
        unsigned short *p=input;
        do { ++p; ++n; } while (*p);
    }
    int count=0;
    if (n) {
        Group *g = &self->groups[1-self->active];
        unsigned short *names=0;
        if (g->mode == 0) {
            count=func_004B3FA0(input,buffer,256,47);
            if (count < 0) { func_0057D9C0(D_006B0458,count&255,count&0x7f00); return; }
            names=func_004B48D0(buffer,256,1);
        } else if (g->mode == 1) {
            count=1;
            func_004B4CA0(self,buffer,256);
            names=buffer;
        } else if (g->mode == 2) {
            count=1;
            func_004B4CA0(self,buffer,256);
            func_004B9438(buffer);
            names=buffer;
        }
        func_004B47F0(buffer,47);
        func_004B47F0(names,47);
        unsigned short *values=buffer;
        for(int i=0;i<count;i++) {
            Item *item=func_004B5A48(self,g->index+i,2);
            item->zero=0;
            item->type=func_004B4950(names);
            func_004B5E00(self,item,values,0);
            values+=length(values)+1;
            names+=length(names)+1;
        }
        func_004B6A38(self);
    }
}
