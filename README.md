# cpp-lab

C++를 학습하고, 예제를 구현하며, 다양한 기능을 실험하기 위한 개인 학습용 저장소입니다.

주로 다음 서적을 기반으로 C++를 공부하고 예제, 실습, 구현 코드를 관리합니다.

- **C++ Primer, 5th Edition**
- **Effective Modern C++**
- **Programming: Principles and Practice Using C++**

단순히 예제 코드를 모아두는 것을 넘어, 학습 과정에서 재사용 가능한 코드는 라이브러리 형태로 분리하고, 테스트와 빌드 시스템까지 함께 관리하는 것을 목표로 합니다.

---

## 프로젝트 구조

```text
cpp-lab/
├── CMakeLists.txt
├── CMakePresets.json
│
├── cmake/
│   ├── CompilerWarnings.cmake
│   └── Sanitizers.cmake
│
├── include/
│   └── 라이브러리의 공개 헤더
│
├── src/
│   └── Core 라이브러리 구현
│
├── examples/
│   └── 예제 및 실습 실행 파일
│
├── tests/
│   └── 단위 테스트
│
└── resource/
    └── 실행에 필요한 리소스 파일
```

각 디렉터리는 다음과 같은 역할을 가집니다.

| 디렉터리 | 설명 |
|---|---|
| `cmake/` | 컴파일러 경고, Sanitizer 등 공통 CMake 모듈 |
| `include/` | 라이브러리의 공개 헤더 |
| `src/` | 재사용 가능한 Core 라이브러리 구현 |
| `examples/` | C++ 기능 학습, 예제 및 실습 코드 |
| `tests/` | GoogleTest 기반 단위 테스트 |
| `resource/` | 프로그램 실행에 필요한 리소스 파일 |

---

## 학습 목표

이 저장소를 통해 다음 내용을 학습하고 구현합니다.

- Modern C++
- C++20 및 이후 언어 기능
- 객체의 생명 주기와 Value Category
- Move Semantics
- RAII와 Resource Management
- Smart Pointer
- C++ Standard Library
- Generic Programming
- Template Programming
- Concepts
- Ranges
- 재사용 가능한 라이브러리 및 추상화 설계
- CMake 기반 Target 중심 빌드 시스템
- GoogleTest를 이용한 단위 테스트
- Compiler Warning 및 Sanitizer를 통한 코드 검증
- 시스템 프로그래밍 및 Low-level Programming 관련 개념

---

## 빌드 시스템

이 프로젝트는 **CMake 기반의 Target 중심 구조**를 사용합니다.

공통 컴파일 경고와 Sanitizer 설정은 각각 `INTERFACE` 라이브러리로 관리합니다.

```text
project_warnings
project_sanitizers
```

각 라이브러리와 실행 파일은 필요한 설정을 명시적으로 연결합니다.

예를 들어:

```cmake
target_link_libraries(
  SomeTarget
  PRIVATE
  project_warnings
  project_sanitizers
)
```

이러한 방식으로 전역 컴파일 옵션 대신 Target 단위로 빌드 설정과 의존성을 관리합니다.

---

## 빌드

기본 빌드:

```bash
cmake -B build
cmake --build build
```

빌드 디렉터리를 제거하고 다시 구성하려면:

```bash
rm -rf build
cmake -B build
cmake --build build
```

---

## Examples

예제와 실습용 실행 파일은 `examples/` 디렉터리에서 관리합니다.

Examples를 제외하고 Core 라이브러리만 빌드하려면:

```bash
cmake -B build -DBUILD_EXAMPLES=OFF
cmake --build build
```

---

## Testing

테스트는 CTest와 GoogleTest를 사용합니다.

`BUILD_TESTING`이 활성화된 경우 GoogleTest는 CMake의 `FetchContent`를 통해 가져옵니다.

빌드:

```bash
cmake -B build
cmake --build build
```

테스트 실행:

```bash
ctest --test-dir build
```

---

## Sanitizers

AddressSanitizer와 UndefinedBehaviorSanitizer를 활성화하려면:

```bash
cmake -B build -DUSE_SANITIZER=ON
cmake --build build
```

---

## Compiler Warnings

GCC 및 Clang 환경에서 다음과 같은 추가 경고 옵션을 사용합니다.

```text
-Wall
-Wextra
-Wpedantic

-Wshadow
-Wconversion
-Wsign-conversion

-Wcast-qual
-Wcast-align

-Wformat=2
-Wnull-dereference

-Wdouble-promotion
```

경고 옵션은 `project_warnings` Target을 통해 관리됩니다.

---

## 프로젝트 방향

이 저장소는 학습 과정에 따라 계속 확장됩니다.

새로운 C++ 기능을 학습하면서 예제와 실습 코드를 `examples/`에 추가하고, 재사용 가치가 있는 구현은 `include/`와 `src/`의 라이브러리로 분리합니다.

또한 필요한 경우 단위 테스트를 `tests/`에 추가하여 코드의 동작을 검증합니다.

```text
학습
  ↓
예제 및 실습
  ↓
반복적인 구현 및 개선
  ↓
재사용 가능한 컴포넌트 분리
  ↓
라이브러리화
  ↓
테스트 추가
```

---

## 참고 서적

- **C++ Primer, 5th Edition**
- **Effective Modern C++**
- **Programming: Principles and Practice Using C++**
- C++20 Get the Details

