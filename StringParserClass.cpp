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
        	char temp1 = *pStart;
        	char temp2 = *pEnd;
        	*pStartTag = temp1;
        	*pEndTag = temp2;
        	areTagsSet = true;
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
        	if(pDataToSearchThru == NULL){
        		return ERROR_DATA_NULL;
        	}
        	if(pStartTag == NULL||pEndTag == NULL){
        		return ERROR_TAGS_NULL;
        	}

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
        	if(pStart == NULL||pEnd == NULL){
        		return ERROR_TAGS_NULL;
        	}
        	int sizeS = strlen(pStart);
        	int sizeT = strlen(pTagToLookFor);
        	for(int i = 0;i <sizeS;i++){
        		if(i+sizeT >sizeS){
        			break;
        		}
        		if(strcmp(pStart,"<") ==0){
        			bool flag = true;

        			for(int j = 0;j<sizeT;j++){
        				if(!pStart == pTagToLookFor[j]){
        					flag = false;
        				}else{
        					pStart++;
        					i++;
        				}
        				}
        			if(flag == true){
        				pEnd = pStart+sizeT;
        				return SUCCESS;
        			}
        		}
        		pStart++;
        	}
        	return FAIL;
        }

