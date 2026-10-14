/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *, void *, void *, int); };
struct Self { char pad0[0x12c]; VEntry *vt; char pad130[0xa90-0x130]; int block[6]; int count; };
struct Car { char pad[0x3444]; int index; };
struct List { int count; int capacity; Car **cars; };
struct Org { char pad[0x60]; List *list; };
extern "C" void RaceOrganization__defaultPosition(char *);
static inline long fill(int n, int *values, List *list) {
    int rank=0, i=0;
    long bound=list->count;
    if(n>0) {
        int *cursor=values;
        do {
            int value=rank;
            rank++;
            *cursor=value;
            i++;
            bound=list->count;
            cursor++;
        } while(i<bound);
    }
    return bound;
}
extern "C" void RaceLanBattleInformation__virtual_13(Self *self, Org *org) {
    List *list = org->list;
    VEntry *entry = self->vt + 15;
    entry->fn((char *)self + entry->delta, org, self->block, self->count);
    RaceOrganization__defaultPosition((char *)org);
    int n = list->count;
    int *values=(int *)__builtin_alloca(n*sizeof(int));
    long bound=fill(n,values,list);
    int j=0;
    if(bound>0) do {
        org->list->cars[j]->index=values[j];
        j++;
    } while(j<list->count);
}
