/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
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
 */

#include "odc/QuantizeManager.h"

#include <gtest/gtest.h>

using namespace onert::odc;

// Test export model path is not set
TEST(odc_QuantizeManager, neg_export_model_path)
{
  QuantizeManager manager("model_path");
  ASSERT_THROW(manager.quantize(), std::runtime_error);
}

// Test invalid model path
TEST(odc_QuantizeManager, neg_invalid_model_path)
{
  QuantizeManager manager("invalid_model_path.circle");
  manager.exportModelPath("export_model_path.circle");
  ASSERT_EQ(manager.quantize(), false);
}
