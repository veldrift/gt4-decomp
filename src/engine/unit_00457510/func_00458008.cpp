/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vision { int tag,base; char pad8[8]; unsigned short w,h; int cells; char pad18[24]; int count,objects; };
struct Entry { int ptr; int pad[3]; };
extern "C" void func_00458008(Vision *p) {
    int i=0;
    int d=(int)p-p->base;
    p->base=(int)p;
    p->cells=d+p->cells;
    for(;i<p->w*p->h;++i) {
        int *slot=(int *)(i*4+p->cells);
        int v=*slot;
        if(v) {
            *slot=d+v;
            int *q=*(int **)(i*4+p->cells);
            int a=*q;
            int next;
            if(a) {
                do {
                    *q=d+a;
                    ++q;
                    next=*q;
                    a=next;
                } while(next);
            }
        }
    }
    int n=p->count;
    Entry *relocated=(Entry *)(d+p->objects);
    p->objects=(int)relocated;
    Entry *q=relocated;
    while(n>0) {
        --n;
        q->ptr=d+q->ptr;
        ++q;
    }
}
