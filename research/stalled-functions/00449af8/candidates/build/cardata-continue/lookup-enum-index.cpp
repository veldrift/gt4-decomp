/* compiler: ee-gcc2.96-nogcse */
struct Entry { int offset,key; };
struct Header { int unknown,count,unknown8,unknownC; Entry entries[1]; };
struct Table { Header *header; };
enum Index { IndexZero=0 };
struct Rows {
 Header *header; Entry *entries;
 Rows(Header *h) : header(h), entries(h->entries) {}
 int key(int index) const { int result=-1; if(index>=0 && index<header->count)result=entries[index].key; return result; }
 char *value(int index) const { return (char *)(entries+header->count)+entries[index].offset+2; }
};
extern "C" char *func_00449AF8(Table *self,int wanted) {
 Header *header=self->header; int count=header->count; if(count<=0)return 0;
 Rows rows(header);for(Index i=IndexZero;i<count;i=(Index)(i+1)) {if(wanted==rows.key(i))return rows.value(i);}
 return 0;
}
