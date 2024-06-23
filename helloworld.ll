@str = private constant [15 x i8] c"Hello, World!\0A\00"

declare i32 @printf(ptr, ...)

define i32 @main() {
  call i32 (ptr, ...) @printf(ptr @str)
  ret i32 0
}
