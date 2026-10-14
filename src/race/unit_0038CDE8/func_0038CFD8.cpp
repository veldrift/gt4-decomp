/* compiler: ee-gcc2.96-nogcse */
struct VEnt { short delta,index; int (*fn)(void *); };
struct Model { char pad[8]; VEnt *vt; };
struct Owner;
struct Rec { char pad[0x18]; Owner *owner; char p1c[0x2880-0x1c]; Model *model; };
struct Table { int n; int unk4; Rec **entries; };
struct World { char pad[0x60]; Table *table; };
struct Link { World *world; };
struct Owner { int unk0; Link *link; };
struct Self { int unk0; int value; int result; };
extern "C" void func_0038CFD8(Self *self,Owner *owner,int arg2) {
    self->value=arg2;
    self->result=0;
    Link *l=(Link *)((int *)owner)[1];
    if(l) {
        World *w=l->world;
        if(w) {
            Table *table=w->table;
            if(table) {
                int count=table->n;
                int i=0;
                if(i<count) do {
                    Rec *r=table->entries[i++];
                    if(r->owner==owner) {
                        Model *model=r->model;
                        if(model) {
                            VEnt *e=model->vt+10;
                            self->result=e->fn((char *)model+e->delta);
                            return;
                        }
                    }
                } while(i<count);
            }
        }
    }
}
