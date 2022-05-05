#pragma once
#include"TTabRecord.h"
#include"TArrayTable.h"
#include"TDataCom.h"
#include<iostream>
#define TabOK 0
#define TabEmpty -101
#define TabFull -102
#define TabNoRecord -103
#define TabRecDouble -104
#define TabNoMem -105
class TDatCom{};
typedef TDatCom* PTDatCom;
class TTable: public TDataCom
{
protected:
	size_t DatCounter;
	int Efficiency;


public:
	TTable() {
		DatCounter = 0;
		Efficiency = 0;
	}
	virtual ~TTable()
	{

	}
	size_t GetDatCount()const {
		return DatCounter;
	}
	int GetEffeciency() const{
		return Efficiency;
	}
	bool IsEmpty()const {
		return DatCounter == 0;
	}
	/*virtual bool IsFull()const {
		return DatCounter >= Tabsize;
	
	}*/
	
	/*virtual TKey GetKey()const {
		return GetKey(current_pos);
	}*/
	/*virtual PTDataValue GetValue()const {
		return GetValueptr(CurrentPos);
	}*/
	virtual TKey Getkey(TDatPos mode)const {
		int pos = -1;
		if (IsEmpty()) {
			switch (mode) {
			case FirstPosition:
				pos = 0;
				break;
			case LastPos:
				pos = DatCounter - 1;
				break;
			default:
				pos = CurrentPos;
				break;
			}
		}
		return TKey(std::to_string(pos));
	}
	/*virtual PTDataValue GetValueptr(TDatPos mode)const {
		PTDataValue value = nullptr;
		if (IsEmpty()) {
			pRecord[CurrentPos]->value;
		}
		return value;
	}*/
	virtual PTDataValue FindRecord(TKey k) = 0;
	virtual void InsRecord(TKey k, PTDataValue pval) = 0;
	virtual void DelRecord(TKey k) = 0;
	virtual int32_t Reset() = 0;
	/*virtual bool Reset() {
		CurrentPos = 0;
		return IsTableEnded();


	}*/
	virtual int32_t GoNext() = 0;
	/*virtual bool GoNext() {
		if (!IsTableEnded()) {
			CurrentPos++;
		}
		return IsTableEnded();
	}*/
	virtual bool isTabEnded() = 0;
	/*int GetCurrentPos()const {
		return CurrentPos;
	}*/
	/*bool SetCurrentPos(int pos) {
		CurrentPos = (pos > -1);
	}*/
	virtual TKey GetKey()const = 0;
	virtual PTDValue GetValue()const = 0;
	friend std::ostream& operator<< (std::ostream& out, TTable& t) {
		for (t.Reset(); t.isTabEnded(); t.GoNext()) {
			out << "Key " << t.GetKey() << " Val" << t.GetValue() << std::endl;
			return out;
		}
	}









};

