/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Config { char pad[0x1040]; float factor[4]; };
struct Cell { int pad0; float value; char pad[0xec-8]; };
struct Self { char pad[0x10]; Config *config; char gap[0x200-0x14]; Cell records[1]; };
struct Table { char pad[8]; unsigned char modes[4]; unsigned char ids[4]; char gap[0x14]; unsigned char next[1]; };
struct View { char pad[8]; unsigned char mode; char gap[3]; unsigned char id; };
struct Record { char pad[0x204]; float value; };
extern "C" Table *func_00359538(Self *) throw();
static inline View *view(char *t, int i) { return (View *)(t+i); }
extern "C" float func_0035A498(Self *self, int i) {
    Table *t = func_00359538(self);
    unsigned char id = t->ids[i];
    char *r = (char *)self + id*0xec;
    float v = ((Record *)r)->value;
    if (t->modes[i] == 2) {
        unsigned char next = ((Table *)t)->next[id];
        char *r2 = (char *)self + next*0xec;
        v += ((Record *)r2)->value;
    }
    return v/self->config->factor[i];
}
