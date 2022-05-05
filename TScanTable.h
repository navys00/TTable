#pragma once
#define TabMaxSize 25
#include"TArrayTable.h"
#include"TTable.h"
#include"TDataCom.h"

class TScanTable:public TArrayTable
{
public:
	TScanTable(int size= TabMaxSize):TArrayTable(size){}
	virtual PTDATValue FindRecord(TKey k) {
		SetRetcode(TabOK);
		int i;
		for (i = 0; i < DatCounter; i++) {
			if (pRecord[i]->Key == k) {
				break;
			}
		}
		Efficiency = i + 1;
		if (i < DatCounter) {
			CurrentPos = i;
			return pRecord[i]->pvalue;
		}
		setretcode(tablenorec);
		return nullptr;
	}
	virtual void InsRecord(TKey key, PTDatValue value) {

	}
	virtual void DelRecord(TKey key) {

	}

};

