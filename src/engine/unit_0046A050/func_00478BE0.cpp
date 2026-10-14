struct Matrix{float v[16];}; struct Render{int word,flag;}; struct Resource;
struct Entry{short words[4];short index,offset;};
struct Record{short words[5];short b;Resource*resource;};
struct Tables{char gap[0x78];Entry*entries;char gap1[0x1C];Matrix*matrices;char gap2[0x14];Record*records;};
struct Obj{char gap[0x6e14];Render*render;unsigned char color[8];Tables*tables;};
struct Input{unsigned short kind;short index,a,b;};
extern "C" void func_00473380(Render*,unsigned),func_00478AF0(Matrix*,int,int,float),func_00478B30(Obj*,Resource*,Matrix*),func_004737A0(Render*,int),func_004AB040(int);
extern "C" unsigned func_0047E658(const unsigned char*,const unsigned char*);
inline Record* record(Tables*t,int index){return &t->records[index];}
extern "C" void func_00478BE0(Input*in,Obj*self){
    Matrix m;
    if (in->kind == 0) {
        func_00473380(self->render, func_0047E658(self->color, (unsigned char*)in + 4));
    } else if ((unsigned short)(in->kind - 1) < 2) {
        Tables *t = self->tables;
        Entry *entry = &t->entries[in->index];
        Record *r = &t->records[entry->index];
        Matrix *src = &t->matrices[in->a];
        m = *src;
        if (in->kind == 1) func_00478AF0(&m, entry->offset, r->b, 0.0f);
        func_00478B30(self, r->resource, &m);
        func_004737A0(self->render, 1);
        return;
    } else if ((unsigned short)(in->kind - 3) < 2) {
        Resource*selected=record(self->tables,in->index)->resource;
        func_00478B30(self, selected, &self->tables->matrices[in->a]);
        if (in->kind == 3) { func_004737A0(self->render, 2); return; }
        func_004737A0(self->render, 1);
        return;
    }
    Render *r = self->render;
    func_004AB040(2);
    r->flag = 0;
}
