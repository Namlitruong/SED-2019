//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Asignment 2 - A VIDEO STORE	
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################

//////////////////////////--Built-in libraries--/////////////////////////////
#pragma once
#include "pch.h"
#include "IC.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

#define ctmIdentifier 'C'
#define itemIdentifier 'I'
#define commentTag '#'

#define ctmDbInLength 6
#define itemDbInLength 7

int initBaseDb(ItemList*, CtmList*);
int finBaseDb(ItemList*, CtmList*);
ctmTypeEnum ctmTypeUtil(string);
rentalTypeEnum rentalTypeUtil(string);
genreTypeEnum genreTypeUtil(string);
bool rentalPeriodUtil(string);
char* str2arr(string);
string ctmTypeStr(ctmTypeEnum);
bool CheckExit(string optSel_str);
string rentalTypeStr(rentalTypeEnum);
string rentalPeriodStr(bool);
string double2str(double);
string genreTypeStr(item*);

int renItem(ItemList*, CtmList*);
int returnItem(ItemList*, CtmList*);
int PromoteCtmrByID(CtmList*);
int promoteCtm(customer*, CtmList*);
int autoPromoteCtmr(CtmList*);
void DispGroupCtmr(CtmList*);
void DisplayOutofStock(ItemList*);
void ModifyCtmr(CtmList*);
void ModifyItem(ItemList*);
void SearchItemCtmr(CtmList*, ItemList*);

string genCtmID(CtmList*);
string genItemID(ItemList* ItsLst, const char* year);