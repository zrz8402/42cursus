In C++, there are quite a few **standard exception types** provided by the STL (Standard Template Library) that you can use instead of writing your own. They cover many common error situations. Here's a categorized breakdown of the most **commonly used standard exceptions**, grouped by type of error:

---

### 🧠 **Logic Errors**
These are errors in the program's logic, detectable before runtime.

- `std::logic_error` (base class)
  - `std::invalid_argument` – e.g., passing an illegal argument to a function
  - `std::domain_error` – e.g., math error like `sqrt(-1)`
  - `std::length_error` – e.g., creating a `std::vector` that’s too long
  - `std::out_of_range` – e.g., accessing a vector element out of bounds

---

### ⚙️ **Runtime Errors**
These occur during program execution.

- `std::runtime_error` (base class)
  - `std::overflow_error` – e.g., numeric overflow
  - `std::underflow_error` – e.g., numeric underflow
  - `std::range_error` – e.g., result out of representable range

---

### 💾 **I/O and System-Level Exceptions**
- `std::ios_base::failure` – file or stream I/O error
- `std::system_error` – errors related to system APIs, threads, etc.
  - `std::filesystem::filesystem_error` – specific to filesystem operations

---

### ⛓️ **Memory and Allocation**
- `std::bad_alloc` – thrown by `new` when memory allocation fails
- `std::bad_array_new_length` – thrown by `new[]` with invalid length

---

### 🎭 **Type and Casting**
- `std::bad_cast` – failed `dynamic_cast`
- `std::bad_typeid` – typeid used on a null pointer to a polymorphic type

---

### 🔧 **Generic and Base Exception**
- `std::exception` – base class for all standard exceptions

---

### 🧰 When to Use These
If you're writing code that:
- accesses containers → use `std::out_of_range`
- processes input → use `std::invalid_argument` or `std::ios_base::failure`
- allocates memory → handle `std::bad_alloc`
- does math or range-sensitive logic → use `std::domain_error`, `std::range_error`, etc.

---