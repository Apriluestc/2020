### 求 1~100 所有数字之和

```bash
#! /bin/bash
i=0
sum=0
for ((; i<=100; ++i))
    do
        let sum+=i
    done
echo $sum
```

### 使用递归的方法求出 1~100 的所有数字之和

```bash
#! /bin/bash
function add() {
    local tmp1=$1
    local tmp2=0
    if [$tmp1 -le 1];then
        sum=1
    else
        tmp=$(($tmp1-1))
        add $tmp2
        sum=(($tmp1+$tmp2))
    fi
    done
    echo $sum
}
```

### 编写一个进度条

```bash
#! /bin/bash
function proc_bar() {
    rate=0
    str=#"
    arr=("|" "/" "-" "\\")
    while [ $rate -le 100  ]
    do
        index=rate%4
        printf " [%-100s] [%d%%] [%s] \r" "$str" "$rate" "${arr[$index]}"
        str=${str}"#"
        let rate++
        usleep 10000
    done
    printf "\n"
}
proc_bar
```
