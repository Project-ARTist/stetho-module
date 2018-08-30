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

#ifndef  ART_MODULES__MODULE_H_
#define  ART_MODULES__MODULE_H_

#include <artist/api/modules/module.h>

using art::Module;
using art::HArtist;
using art::MethodInfo;
using art::CodeLib;
using art::Filter;
using art::FilesystemHelper;

class TemplateModule : public Module {
  HArtist * createPass(const MethodInfo &method_info) const OVERRIDE;

  shared_ptr<const CodeLib> createCodeLib() const OVERRIDE;

public:
  explicit TemplateModule(const shared_ptr<const FilesystemHelper> fs);

  unique_ptr<Filter> getMethodFilter() const OVERRIDE;
};

#endif  // ART_MODULES__MODULE_H_
