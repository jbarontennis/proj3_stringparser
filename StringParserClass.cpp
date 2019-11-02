/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
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

        int KP_StringParserClass::StringParserClass::getDataBetweenTags(
                char* pDataToSearchThru, std::vector<std::string>& myVector) {

        }

        void KP_StringParserClass::StringParserClass::cleanup() {

        }

        int KP_StringParserClass::StringParserClass::findTag(char* pTagToLookFor,
                char*& pStart, char*& pEnd) {

        }

