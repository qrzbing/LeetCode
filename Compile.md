# 编译选项

目前还是手动编译，未来需要添加自动编译

``` bash
g++ -g -o bin/test -fsanitize=address codes/xxx.cpp
```

- [ ] 根据输入编译，比如 `make 3` 就编译第三题，不知道是否能实现。