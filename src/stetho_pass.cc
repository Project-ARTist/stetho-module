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
 * @author "Alexander Fink <alexander.fink@cispa.saarland>"
 * @author "Maximilian Jung <maxjung96@gmx.de>"
 * @author "Oliver Schranz <oliver.schranz@cispa.saarland>"
 *
 */

#include <atomic>

#include <artist/api/io/artist_log.h>
#include <artist/api/io/error_handler.h>

#include "stetho_pass.h"
#include "codelib.h"

using std::string;
using std::vector;
using std::find_if;

using art::INFO;
using art::HIntConstant;
using art::HParameterValue;
using art::ErrorHandler;

using art::ArtUtils;
using art::Primitive;

void HStethoArtist::RunPass() {
    const auto eblock = graph_->GetEntryBlock();
    if (eblock != nullptr) {
      const auto block = eblock->GetSingleSuccessor();
      if (block != nullptr) {
        if (!_method_info.GetParams().empty()) {
          HParameterValue *this_instruction = _method_info.GetParams()[0];
          if (_method_info.IsThisParameter(this_instruction)) {
            auto cursor = block->GetFirstInstruction();
            string invoked_signature;
            auto codelib_instruction = GetCodeLibInstruction();
            vector<art::HInstruction *> params;
            params.push_back(codelib_instruction);
            if (_method_info.GetMethodName(true).find("networkInterceptors(") != string::npos) {
              invoked_signature = StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP2INTERCEPTOR__L__V;
              params.push_back(this_instruction);
            } else if (_method_info.GetMethodName(true).find("onCreate(") == string::npos) {
              invoked_signature = StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__OKHTTP3INTERCEPTOR__L__V;
              params.push_back(_method_info.GetParams()[1]);
            } else {
              invoked_signature = StethoCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INITSTETHO__L__V;
              params.push_back(this_instruction);
            }
            ArtUtils::InjectMethodCall(cursor, invoked_signature, params, this->getCodeLibEnvironment(),
                                       Primitive::Type::kPrimVoid, true);
          } else {
            // 1st parameter is not this
          }
        } else {
          // no params
        }
      } else {
        // no second block
      }
    } else {
      // no entry block
    }

}
