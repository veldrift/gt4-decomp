// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mRaceRecord:hObject {void* const data;mRaceRecord(void*) __asm__("func_001A6E40");virtual ~mRaceRecord();};
mRaceRecord::mRaceRecord(void* value):data(value){}
