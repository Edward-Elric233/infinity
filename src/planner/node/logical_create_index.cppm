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

import stl;
import logical_node_type;
import column_binding;
import logical_node;
import parser;

export module logical_create_index;

namespace infinity {

class IndexDef;

export class LogicalCreateIndex : public LogicalNode {
public:
    [[nodiscard]] Vector<ColumnBinding> GetColumnBindings() const final;

    [[nodiscard]] SharedPtr<Vector<String>> GetOutputNames() const final;

    [[nodiscard]] SharedPtr<Vector<SharedPtr<DataType>>> GetOutputTypes() const final;

    String ToString(i64 &space) const final; // TTT shenyushi: should be const

    inline String name() override { return "LogicalCreateIndex"; }

public:
    static inline SharedPtr<LogicalCreateIndex>
    Make(u64 node_id, SharedPtr<String> schema_name, SharedPtr<String> table_name, SharedPtr<IndexDef> index_def, ConflictType conflict_type) {
        return MakeShared<LogicalCreateIndex>(node_id, schema_name, table_name, index_def, conflict_type);
    }

    inline LogicalCreateIndex(u64 node_id,
                              SharedPtr<String> schema_name,
                              SharedPtr<String> table_name,
                              SharedPtr<IndexDef> index_def,
                              ConflictType conflict_type)
        : LogicalNode(node_id, LogicalNodeType::kCreateIndex), schema_name_(schema_name), table_name_(table_name), index_definition_(index_def),
          conflict_type_(conflict_type) {}

public:
    [[nodiscard]] inline SharedPtr<String> schema_name() const { return schema_name_; }

    [[nodiscard]] inline SharedPtr<String> table_name() const { return table_name_; }

    [[nodiscard]] inline SharedPtr<IndexDef> index_definition() const { return index_definition_; }

    [[nodiscard]] inline ConflictType conflict_type() const { return conflict_type_; }

private:
    SharedPtr<String> schema_name_{};
    SharedPtr<String> table_name_{};
    SharedPtr<IndexDef> index_definition_{};
    ConflictType conflict_type_{ConflictType::kInvalid};
};
} // namespace infinity