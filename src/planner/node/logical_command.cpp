// Copyright(C) 2023 InfiniFlow, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

module;

import std;

import stl;
import column_binding;
import logical_node_type;
import parser;

import infinity_exception;

module logical_command;

namespace infinity {

Vector<ColumnBinding> LogicalCommand::GetColumnBindings() const { return {}; }

SharedPtr<Vector<String>> LogicalCommand::GetOutputNames() const {
    SharedPtr<Vector<String>> result = MakeShared<Vector<String>>();
    result->emplace_back("OK");
    return result;
}

SharedPtr<Vector<SharedPtr<DataType>>> LogicalCommand::GetOutputTypes() const {
    SharedPtr<Vector<SharedPtr<DataType>>> result_type = MakeShared<Vector<SharedPtr<DataType>>>();
    result_type->emplace_back(MakeShared<DataType>(LogicalType::kInteger));
    return result_type;
}

String LogicalCommand::ToString(i64 &space) const {
    std::stringstream ss;
    String arrow_str;
    if (space > 3) {
        space -= 4;
        arrow_str = "->  ";
    }

    switch (command_info_->type()) {
        case CommandType::kUse: {
            UseCmd *use_cmd_info = (UseCmd *)(command_info_.get());
            ss << String(space, ' ') << arrow_str << "Use table: " << use_cmd_info->db_name();
        }
        case CommandType::kInvalid: {
            Error<PlannerException>("Invalid command type.");
        }
    }

    space += arrow_str.size();

    return ss.str();
}

} // namespace infinity