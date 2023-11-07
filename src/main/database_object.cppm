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

export module database_object;

namespace infinity {

export enum class ObjectType {
    kInfinity,
    kDatabase,
    kTable,
    kInvalid,
};

export class DatabaseObject {
public:
    explicit DatabaseObject(ObjectType object_type) : object_type_(object_type) {}

private:
    ObjectType object_type_ { ObjectType::kInvalid };
};

}
