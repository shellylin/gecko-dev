/*
 * Copyright 2015, Mozilla Foundation and contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __RefCount_h__
#define __RefCount_h__

#include <stdint.h>

// Note: Not thread safe!
class RefCounted {
public:
  void AddRef() {
    ++mRefCount;
  }

  uint32_t Release() {
    uint32_t newCount = --mRefCount;
    if (!newCount) {
      delete this;
    }
    return newCount;
  }

protected:
  RefCounted()
    : mRefCount(0)
  {
  }
  virtual ~RefCounted()
  {
  }
  uint32_t mRefCount;
};

template<class T>
class RefPtr {
public:
  explicit RefPtr(T* aPtr) : mPtr(nullptr) {
    Assign(aPtr);
  }
  ~RefPtr() {
    Assign(nullptr);
  }
  T* operator->() const { return mPtr; }

  RefPtr& operator=(T* aVal) {
    Assign(aVal);
    return *this;
  }

private:
  void Assign(T* aPtr) {
    if (mPtr) {
      mPtr->Release();
    }
    mPtr = aPtr;
    if (mPtr) {
      aPtr->AddRef();
    }
  }
  T* mPtr;
};

#endif // __RefCount_h__
