struct Entry { unsigned short a,b,c,d; };
struct Table { char pad[0x10]; Entry* entries; };
extern "C" int func_004C3A88(Table* t,unsigned short index) {
if((unsigned short)(index-1) >= 0x1fff) return -1;
Entry* e=&t->entries[index];
e->a=0xffff; e->b=0xffff; e->c=0xffff; e->d=0xffff;
return 0;
}
