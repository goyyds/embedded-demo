### 嵌入式

##### 1.安装sdcc
```shell
brew install sdcc
```

#### 2.编写代码
```shell
main.c

xxxxxx


xxxxxx
```

#### 3.编译
```shell
sdcc main.c
```

#### 4.将.ihx文件转化为.hex文件
```shell
packihx main.ihx > main.hex
```

#### 5.烧录
```shell

```

#### 其他

.ihx->.bin
```shell
# 1.bin 文件
sdobjcopy -I ihex -O binary main.ihx main.bin

#2.链接文件

sdcc -c main.c
#再编译
sdcc main.rel
```