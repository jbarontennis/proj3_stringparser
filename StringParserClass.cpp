/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include <vector>
#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"
#include "stdlib.h"
 	 	char    *pStartTag;
        char    *pEndTag;
        bool    areTagsSet;
        KP_StringParserClass::StringParserClass::StringParserClass(void) {
            pStartTag = NULL;
            pEndTag = NULL;
            areTagsSet = false;
        }

        KP_StringParserClass::StringParserClass::~StringParserClass(void) {
            cleanup();
        }
        //these are the start tag and the end tags that we want to find,
        		//presumably the data of interest is between them, please make a
        		//COPY of what pStartTag and pEndTag point to.  In other words
        		//DO NOT SET pStartTag = pStart
        		//returns:
        		//SUCCESS
        		//ERROR_TAGS_NULL if either pStart or pEnd is null
        int KP_StringParserClass::StringParserClass::setTags(const char* pStart, const char* pEnd) {
        	if(pStart == NULL||pEnd == NULL){
        		return ERROR_TAGS_NULL;
        	}
        	pStartTag = strdup(pStart);
        	pEndTag = strdup(pEnd);
        	/*char temp1 = *pStart;
        	char temp2 = *pEnd;
        	*pStartTag = temp1;
        	*pEndTag = temp2;
        	areTagsSet = true;*/
        	return SUCCESS;
        }
        //First clears myVector
        		//going to search thru pDataToSearchThru, looking for info bracketed by
        		//pStartTag and pEndTag, will add that info only to myVector
        		//returns
        		//SUCCESS  finished searching for data between tags, results in myVector (0 or more entries)
        		//ERROR_TAGS_NULL if either pStart or pEnd is null
        		//ERROR_DATA_NULL pDataToSearchThru is null
        int KP_StringParserClass::StringParserClass::getDataBetweenTags(
                char* pDataToSearchThru, std::vector<std::string>& myVector) {
        	myVector.clear();
        	if(pStartTag == NULL||pEndTag == NULL){
        	    return ERROR_TAGS_NULL;
        	}
        	if(pDataToSearchThru == NULL){
        		return ERROR_DATA_NULL;
        	}

        	char*endOfTag =0;
        	std::string message;
        	int endTagLength = strlen(pEndTag);
        	bool eofFlag = false;
        	bool marked = false;
        	while(!eofFlag){
        	if(findTag(pStartTag,pDataToSearchThru,endOfTag) == SUCCESS){
        		pDataToSearchThru = endOfTag;
        		message = "";
        		while(strncmp(pDataToSearchThru,"</",2)){
        			std::string it = pDataToSearchThru;
        			std::string str = it.substr(0,1);
        			message.append(str);
        			pDataToSearchThru++;
        		}
        		myVector.push_back(message);
        		pDataToSearchThru = pDataToSearchThru+endTagLength;

        	}else{
        		eofFlag = true;
        	}
        	}

        	            return SUCCESS;
        }

        void KP_StringParserClass::StringParserClass::cleanup() {

        }
        //Searches a string starting at pStart for pTagToLookFor
        		//returns:
        		//SUCCESS  found pTagToLookFor, pStart points to beginning of tag and pEnd points to end of tag
        		//FAIL did not find pTagToLookFor and pEnd points to 0
        		//ERROR_TAGS_NULL if either pStart or pEnd is null
        int KP_StringParserClass::StringParserClass::findTag(char* pTagToLookFor,
                char*& pStart, char*& pEnd) {
        	if(pStart == NULL){
        		return ERROR_TAGS_NULL;
        	}
        	int sizeS = strlen(pStart);
        	int sizeT = strlen(pTagToLookFor);
        	int i = 0;
        	char* tmp = pTagToLookFor;
        	char* tmp2= pStart;
        	while(pStart != ""){
        		if(i+sizeT >sizeS){
        			break;
        		}
        		if(strncmp(pStart,"<",1) ==0){
        			tmp = pTagToLookFor;
        			tmp2 = pStart;
        			bool flag = true;

        			for(int j = 0;j<sizeT;j++){

        				if(strncmp(tmp2,tmp,1) !=0){
        					flag = false;
        				}else{
        					tmp2++;
        					i++;
        					tmp++;
        				}
        				}
        			if(flag == true){
        				pEnd = pStart+sizeT;
        				return SUCCESS;
        			}
        		}
        		pStart++;
        		i++;
        	}
        	return FAIL;
        }

