// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __CORE_HPP__
#define __CORE_HPP__

#include <string>

#include <process/future.hpp>

#include "slave/containerizer/mesos/isolators/cgroups2/controller.hpp"
#include "slave/flags.hpp"

namespace mesos {
namespace internal {
namespace slave {

// Controller to interface with the cgroups core control files. That is,
// control files "cgroup.*", which exist in all cgroups.
class CoreControllerProcess : public ControllerProcess
{
public:
  static Try<process::Owned<ControllerProcess>> create(
      const Flags& flags);

  ~CoreControllerProcess() override = default;

  std::string name() const override;

  process::Future<ResourceStatistics> usage(
      const ContainerID& containerId,
      const std::string& cgroup) override;

private:
  CoreControllerProcess(const Flags& flags);
};

} // namespace slave {
} // namespace internal {
} // namespace mesos {

#endif // __CORE_HPP__
