/* compiler: ee-gcc2.96-nogcse */
struct Entry { int offset,key; };
struct Header { int unknown,count,unknown8,unknownC; Entry entries[1]; };
struct Table { Header *header; };
struct Rows {
 Header *header; Entry *entries;
 Rows(Header *h) : header(h), entries(h->entries) {}
 Entry row(int index) const { Entry result; result.offset=0; result.key=-1; if(index>=0 && index<header->count)result=entries[index]; return result; }
 char *value(int index) const { return (char *)(entries+header->count)+entries[index].offset+2; }
};
extern "C" char *func_00449AF8(Table *self,int wanted) {
 Header *header=self->header; int count=header->count; if(count<=0)return 0;
 Rows rows(header);for(int i=0;i<count;++i) {if(wanted==rows.row(i).key)return rows.value(i);}
 return 0;
}
