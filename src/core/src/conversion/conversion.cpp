/**
 * Copyright 2014 University of Bremen, Institute for Artificial Intelligence
 * Author(s): Ferenc Balint-Benczedi <balintbe@cs.uni-bremen.de>
 *         Thiemo Wiedemeyer <wiedemeyer@cs.uni-bremen.de>
 *         Jan-Hendrik Worch <jworch@cs.uni-bremen.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <rs/conversion/conversion.h>
#include <rs/utils/output.h>

using namespace rs::conversion;

ConversionException::ConversionException(const std::string &msg) : std::exception(), msg(msg)
{
}

ConversionException::~ConversionException() throw()
{
}

const char *ConversionException::what() const throw()
{
  return msg.c_str();
}

template<typename T>
void from(const uima::FeatureStructure &fs, T &output)
{
  std::string msg = std::string("no conversion for type '") + typeid(T).name() + "' defined";
  outError(msg);
  throw ConversionException(msg);
}

template<typename T>
uima::FeatureStructure to(uima::CAS &cas, const T &input)
{
  std::string msg = std::string("no conversion for type '") + typeid(T).name() + "' defined";
  outError(msg);
  throw ConversionException(msg);
}
