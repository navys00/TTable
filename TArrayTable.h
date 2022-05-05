#pragma once
#include"TTable.h"
#include"TDataValue.h"
enum TDatPos {
	FirstPosition, CurrentPos, LastPos
};
class TArrayTable: public TTable 
{
protected:
	PTTabRecord* pRecord;//=pResc
	int Tabsize;
	int CurPos;
public:
	TArrayTable(int size=100) {
		Tabsize = size;
		pRecord = new PTTabRecord[size];
		for (int i = 0; i < Tabsize; i++) {
			pRecord[i] = nullptr;
		}
		CurPos = 0;

	}
	virtual ~TArrayTable()
	{
		for(int i = 0; i < DatCounter; i++) {
			delete pRecord[i];
		}
		delete[] pRecord;
	}
	virtual bool ISfull() {
		return DatCounter >= Tabsize;
	}
	int GetTabSize()const {
		return Tabsize;
	}
	virtual TKey GetKey()const {
		return GetKey(TDatPos::CurrentPos);
	}
	virtual TKey GetKey(TDatPos mode)const {
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
	virtual PTDataValue GetValue()const {
		return GetValueptr(CurrentPos);
	}
	virtual PTDataValue GetValueptr(TDatPos mode)const {
		PTDataValue value = nullptr;
		int32_t pos = -1;
		if (!IsEmpty()) {
			switch (mode) {
			case FirstPosition: pos = 0; break;
			case LastPos: pos = DatCounter - 1; break;
			default: pos = CurPos; break;
			}
		}
		value = pRecord[pos]->Pvalue;
		return value;
	}
	virtual bool SetCurrentPos(int pos) {
		CurPos = (pos > -1) && (pos < DatCounter) ? pos : 0;
		return IsTableEnded();
	}
	virtual bool IsTableEnded()const {
		return CurPos >= Tabsize;

	}
	int GetCurrentPos()const {
		return CurPos;
	}
};

