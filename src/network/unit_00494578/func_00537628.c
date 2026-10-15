typedef struct Packet { unsigned char a,b; unsigned short size; short x; unsigned short index; char pad[8]; int off; char data[1]; } Packet;
typedef struct Item { int state; unsigned int count; int x; int total; char pad[0x10]; int h20; unsigned char *flags; char *data; } Item;
typedef void (*Callback)(int,int,int,char *);
Item *func_00537C20(int,int,Packet *);
void *func_005A4724(void *,const void *,unsigned int);
void func_0053A7B8(void *);
int func_0053A510(unsigned int,unsigned int,Callback *);
void func_00531738(void *);
int func_00537628(int a,int b,int c,Packet *packet) {
    Callback cb;
    int complete = 1;
    Item *item;
    unsigned int n, i;
    if (!a) return -1;
    item = func_00537C20(a,c,packet);
    if (item) {
        func_005A4724(item->data + packet->off,packet->data,packet->size);
        item->total += packet->size;
        func_0053A7B8(&item->h20);
        item->flags[packet->index] = 1;
        n = item->count;
        for (i = 0; i < n; i++) {
            if (item->flags[i] == 0) { complete = 0; break; }
        }
        if (complete) {
            cb = 0;
            func_0053A510(packet->a,packet->b,&cb);
            if (cb) cb(a,b,c,item->data);
            func_00531738(&item->data);
            func_00531738(&item->flags);
            item->state = 0;
        }
    }
    return packet->size + 20;
}
