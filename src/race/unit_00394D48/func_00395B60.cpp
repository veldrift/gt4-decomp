/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Key { int v[8]; };
struct Entry { char pad[12]; unsigned short n; char padE[14]; Key *keys; };
struct Runway { char pad[0x44]; unsigned short n; char pad46[0x2a]; Key *keys; char pad74[0x28]; Entry *entries; };
struct Course { char pad[0xbc]; int x; };
struct Self { int pad0; Course *course; int pad8; void *map; char pad10[0xa0]; int entry; };
extern "C" Runway *CourseData__getRunway(Course *);
extern "C" void *func_003E4E50(void *,int *);
extern "C" void func_00395B60(Self *s) {
    Course *c = s->course;
    if (c->x != 0) {
        void *m = s->map;
        if (m) {
            int i=0;
            unsigned short n=CourseData__getRunway(c)->n;
            for (;i<(int)n;i++) {
                Runway *r=CourseData__getRunway(s->course);
                func_003E4E50(m, (int *)(r->keys+i));
            }
            if (s->entry >= 0) {
                i=0;
                Entry *entry=CourseData__getRunway(s->course)->entries+s->entry;
                n=entry->n;
                for (;i<(int)n;i++) {
                    Runway *r=CourseData__getRunway(s->course);
                    Entry *e=r->entries+s->entry;
                    func_003E4E50(m, (int *)(e->keys+i));
                }
            }
        }
    }
}
