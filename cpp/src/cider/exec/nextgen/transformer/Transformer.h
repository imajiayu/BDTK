/*
 * Copyright(c) 2022-2023 Intel Corporation.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef CIDER_EXEC_NEXTGEN_TRANSFORMER_H
#define CIDER_EXEC_NEXTGEN_TRANSFORMER_H

#include "exec/nextgen/operators/OpNode.h"

namespace cider::exec::nextgen::transformer {
/// \brief The Transformer class is responsible for transforming the OpPipeline to a
/// translator
class Transformer {
 public:
  static operators::TranslatorPtr toTranslator(
      operators::OpPipeline& pipeline,
      const context::CodegenOptions& co = context::CodegenOptions());
};
}  // namespace cider::exec::nextgen::transformer

#endif  // CIDER_EXEC_NEXTGEN_TRANSFORMER_H
