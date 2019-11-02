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

        int KP_StringParserClass::StringParserClass::setTags(const char* pStart, const char* pEnd) {

        }

        int KP_StringParserClass::StringParserClass::getDataBetweenTags(
                char* pDataToSearchThru, std::vector<std::string>& myVector) {

        }

        void KP_StringParserClass::StringParserClass::cleanup() {

        }

        int KP_StringParserClass::StringParserClass::findTag(char* pTagToLookFor,
                char*& pStart, char*& pEnd) {

        }

