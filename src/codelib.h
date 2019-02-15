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

#ifndef ART_MODULES_STETHO_STETHO_CODELIB_H_
#define ART_MODULES_STETHO_STETHO_CODELIB_H_


#include <string>
#include <unordered_set>
#include <artist/api/modules/codelib.h>

using std::string;
using std::unordered_set;

using art::CodeLib;

class StethoCodeLib : public CodeLib {
    public:
    // METHODS //////////////////////////////////
    static const string _M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INITSTETHO__L__V;
    static const string _M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP3INTERCEPTOR__L__V;
    static const string _M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP2INTERCEPTOR__L__V;
    // FIELDS ///////////////////////////////////
    static const string _F_CODECLASS_INSTANCE;
    // CLASSES //////////////////////////////////
    static const string _C_JAVA_LANG_OBJECT;
    static const string _C_CODECLASS;
    static const string _C_JAVA_LANG_STRING;

    public:
        StethoCodeLib() = default;
        StethoCodeLib(const StethoCodeLib& other) = default;
        StethoCodeLib(StethoCodeLib&& other) = default;

        ~StethoCodeLib() override = default;

        StethoCodeLib& operator=(const StethoCodeLib&) = default;
        StethoCodeLib& operator=(StethoCodeLib&&) = default;

        unordered_set<string>& getMethods() const override;
        string& getInstanceField() const override;
        string& getCodeClass() const override;
};  // class StethoCodeLib


#endif  // ART_MODULES_STETHO_STETHO_CODELIB_H_
