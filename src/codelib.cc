/**
 * The ARTist Project (https://artist.cispa.saarland)
 *
 * Copyright (C) 2018 CISPA (https://cispa.saarland), Saarland University
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "codelib.h"


// CODE_GENERATOR //////////////////////////////////////////////////////////////////////////////////////////////////////
// METHODS //////////////////////////////////
const string StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INITSTETHO__L__V =
    "Lsaarland/cispa/artist/codelib/CodeLib;initStetho(Ljava/lang/Object;)V";
const string StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP3INTERCEPTOR__L__V("Lsaarland/cispa/artist/codelib/CodeLib;okhttp3interceptor(Ljava/lang/Object;)V");
const string StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP2INTERCEPTOR__L__V("Lsaarland/cispa/artist/codelib/CodeLib;okhttp2interceptor(Ljava/lang/Object;)V");

// FIELDS ///////////////////////////////////
const string StethoCodeLib::_F_CODECLASS_INSTANCE =
    "Lsaarland/cispa/artist/codelib/CodeLib;INSTANCE";

// CLASSES //////////////////////////////////
const string StethoCodeLib::_C_JAVA_LANG_OBJECT =
    "Ljava/lang/Object;";
const string StethoCodeLib::_C_CODECLASS =
    "Lsaarland/cispa/artist/codelib/CodeLib;";
const string StethoCodeLib::_C_JAVA_LANG_STRING =
    "Ljava/lang/String;";

unordered_set<string> &StethoCodeLib::getMethods() const {
    static unordered_set<string> methods({
    StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INITSTETHO__L__V,
    StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP3INTERCEPTOR__L__V,
    StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP2INTERCEPTOR__L__V,
    });
    return methods;
}

string &StethoCodeLib::getInstanceField() const {
    static string instanceField = StethoCodeLib::_F_CODECLASS_INSTANCE;
    return instanceField;
}

string &StethoCodeLib::getCodeClass() const {
    static string codeClass = StethoCodeLib::_C_CODECLASS;
    return codeClass;
}


// CODE_GENERATOR END //////////////////////////////////////////////////////////////////////////////////////////////////


