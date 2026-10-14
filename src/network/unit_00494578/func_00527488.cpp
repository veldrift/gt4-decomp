struct Owner;struct Message;struct Packet;
struct Self{Owner*owner;};
struct Record{int type;Message*first,*second;int firstValid,secondValid;};
extern "C" int func_00529770(Owner*,Message*,unsigned short,Packet*);
extern "C" int func_00527488(Self*self,Record*record,unsigned short flags,Packet*packet){int result=0xd2f3;if(record->first && record->firstValid){result=func_00529770(self->owner,record->first,flags,packet);if(result)return result;}else if(record->second && record->secondValid){result=func_00529770(self->owner,record->second,flags,packet);if(result)return result;}return result;}
