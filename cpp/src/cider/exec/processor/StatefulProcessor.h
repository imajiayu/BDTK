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

#ifndef CIDER_STATEFUL_PROCESSOR_H
#define CIDER_STATEFUL_PROCESSOR_H

#include "exec/processor/DefaultBatchProcessor.h"

namespace cider::exec::processor {

class StatefulProcessor : public DefaultBatchProcessor {
 public:
  StatefulProcessor(const plan::SubstraitPlanPtr& plan,
                    const BatchProcessorContextPtr& context,
                    const cider::exec::nextgen::context::CodegenOptions& codegen_options);

  void getResult(struct ArrowArray& array, struct ArrowSchema& schema) override;

  Type getProcessorType() const override { return Type::kStateful; };

 private:
  bool has_groupby_{false};
};

}  // namespace cider::exec::processor

#endif  // CIDER_STATEFUL_PROCESSOR_H
