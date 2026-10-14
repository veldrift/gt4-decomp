struct Entry{int offset,id;};struct Data{int unknown,count,unknown8,unknownC;Entry entries[0];};struct Table{Data*data;};
extern "C" unsigned func_0057F260(const char*);extern "C" int func_00449968(Table*,const char*,int,unsigned);
inline int idAt(Table*self,int i){int id=-1;if(i>=0){Data*d=self->data;if(i<d->count){int offset=i*8;char*entry=(char*)d+offset;id=*(int*)(entry+0x14);};}return id;}
extern "C" int func_00449A20(Table*self,const char*name){int low=-1;unsigned length=func_0057F260(name);int high=self->data->count;for(;;){int index=(low+high)>>1;int comparison=func_00449968(self,name,index,length);if(comparison==0)return idAt(self,index);if(comparison>0)low=index;else high=index;if(low+1==high)break;}return -1;}
