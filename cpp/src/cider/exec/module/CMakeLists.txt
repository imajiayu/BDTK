# Copyright(c) 2022-2023 Intel Corporation.
#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

find_package(gflags COMPONENTS shared)
set(SRC_FILE
    ../../function/ExtensionFunctionsBinding.cpp
    ../../function/ExtensionFunctionsWhitelist.cpp
    ../../function/FunctionLookupEngine.cpp
    CiderTypes.cpp
    CiderOptions.cpp
    batch/CiderBatchUtils.cpp
    batch/CiderArrowBufferHolder.cpp)
add_library(cider SHARED ${SRC_FILE})
if(NOT LIBSUBSTRAITCPP_INCLUDE_DIR
   OR NOT LIBSUBSTRAITCPP_FUNCTION_LIB
   OR NOT LIBSUBSTRAITCPP_TYPE_LIB)
  add_dependencies(cider SUBSTRAITCPP)
endif()
target_link_libraries(
  cider
  QueryEngine
  nextgen
  cider_plan_parser
  cider_function
  ${Boost_LIBRARIES}
  ${GFLAGS_LIBRARIES}
  ${TBB_LIBS}
  ${SUBSTRAITCPP_FUNCTION_LIB}
  ${SUBSTRAITCPP_TYPE_LIB}
  ${SUBSTRAITCPP_COMMON_LIB}
  substrait
  yaml-cpp
  cider_hashtable_join)

set_target_properties(cider PROPERTIES VERSION "${BDTK_FULL_SO_VERSION}"
                                       SOVERSION "${BDTK_SO_VERSION}")

install(
  TARGETS cider
  DESTINATION "lib"
  COMPONENT "CIDER")
install(
  FILES CiderInterface.h CiderOptions.h CiderTableSchema.h CiderException.h
  DESTINATION "Cider"
  COMPONENT "include")
