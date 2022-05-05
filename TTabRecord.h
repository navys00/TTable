#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TTable.h"
typedef std::string TKey;
typedef TDataValue* PTDValue;
//класс строчки таблицы
class TTabRecord:TDatValue
{
protected:
	TKey Key;
	PTDValue Pvalue;
	virtual void print() {
		std::cout<<Key<<" "<<*Pvalue;
	}
	
public:
	TTabRecord(TKey _key, PTDValue value ) {
		Key = _key;
		Pvalue = value;
	}

	void SetKey(TKey k) {
		Key = k;
	}
	TKey GetKey() {
		return this->Key;
	}
	void SetValue(PTDValue value) {
		Pvalue = value;
	}
	PTDValue GetValue() {
		return Pvalue;
	}
    virtual	PTDValue* GetCopy() {
	return new TDatValue(Key, Pvalue);
	}
	TTabRecord operator=(const TTabRecord& tr) {
		Key = tr.Key;
		Pvalue = tr.Pvalue;//Getcopy() ? setvalue()?
		return *this;
	}
	virtual bool operator==(const TTabRecord& tr)const {
		return Key == tr.Key;
	}
	virtual bool operator>(const TTabRecord& tr) const{
		return Key > tr.Key;
	}
	virtual bool operator<(const TTabRecord& tr) const{
		return Key < tr.Key;
	}
	friend class TArrayTable;
	friend class TSortTable;
	friend class TScanTable;
	friend class TTreeTable;
	friend class TTreeNode;
	friend class THashNode;
	friend class TArrayHashTable;
	friend class TListHashTable;


};
typedef TTabRecord* PTTabRecord;

