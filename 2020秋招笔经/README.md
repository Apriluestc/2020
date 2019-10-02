# 2020 届秋招笔经

* [实现生产者消费者模型](#实现生产者消费者模型)
* [实现 LRU](#实现-lru)
* [线程安全的单例模式](#线程安全的单例模式)
* [实现 string 类](#实现-string-类)

### 实现生产者消费者模型

**描述**：一群生产者和一群消费者提供产品，共享缓冲区

**规则**：不能向满缓冲区写数据，不能向空缓冲区取数据，每个时刻仅允许 1 个生产者或消费者拿或取走一个数据

```cpp
void producer() {
    while (true) {
        // 生产一个数据
        P(empty);
        P(mutex);
        // 存一个数据到缓冲区
        V(mutex);
        V(empty);
    }
}

void consumer() {
    while (true) {
        P(full);
        P(mutex);
        // 从缓冲区取 1 个数据
        V(mutex);
        V(empty);
    }
}
```

### 实现 LRU

**算法描述**：LRU 算法实际上是让你设计数据结构：首先要接收一个 capacity 参数作为缓存的最大容量，然
后实现两个 API，一个是 put(key, val) 方法存入键值对，另一个
是 get(key) 方法获取 key 对应的 val，如果 key 不存在则返回 -1。

```cpp
// 缓存容量为 2
LRUCache cache = new LRUCache(2);

// 你可以把 cache 理解成一个队列
// 假设左边是队头，右边是队尾
// 最近使用的排在队头，久未使用的排在队尾
// 圆括号表示键值对 (key, val)

cache.put(1, 1);

// cache = [(1, 1)]
cache.put(2, 2);

// cache = [(2, 2), (1, 1)]
cache.get(1);       // 返回 1

// cache = [(1, 1), (2, 2)]
// 解释：因为最近访问了键 1，所以提前至队头
// 返回键 1 对应的值 1
cache.put(3, 3);

// cache = [(3, 3), (1, 1)]
// 解释：缓存容量已满，需要删除内容空出位置
// 优先删除久未使用的数据，也就是队尾的数据
// 然后把新的数据插入队头
cache.get(2);       // 返回 -1 (未找到)

// cache = [(3, 3), (1, 1)]
// 解释：cache 中不存在键为 2 的数据
cache.put(1, 4);    

// cache = [(1, 4), (3, 3)]
// 解释：键 1 已存在，把原始值 1 覆盖为 4
// 不要忘了也要将键值对提前到队头
```

**设计原则**：如果一个数据在最近一段时间没有被访问到，那么在将来它被访问的可能性也很小。也就是说，当限定的空间已存满数据时，应当把最久没有被访问到的数据淘汰。

**这个算法的出发点在于**：某个页面被访问了，则它可能马上还要访问，反之，如过很长时间没被访问，则它在最近一段时间也不会被访问

**最近最久未使用算法示例**：假定系统为某进程分配了 3 个物理块，进程运行时的页面走向为 1，2，3，4，1，2，5，1，2，3，4，5，开始时 3 个物理块均为空，计算采用 最近最久未使用页
面淘汰算法时的缺页率 ？（10/12）

| 页面走向 |  1   |  2   |  3   |  4   |  1   |  2   |  5   |  1   |  2   |  3   |  4   |  5   |
| :------: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 物理块 1 |  1   |  1   |  1   |  4   |  4   |  4   |  5   |      |      |  3   |  3   |  3   |
| 物理块 2 |      |  2   |  2   |  2   |  1   |  1   |  1   |      |      |  1   |  4   |  4   |
| 物理块 3 |      |      |  3   |  3   |  3   |  2   |  2   |      |      |  2   |  2   |  5   |
|   缺页   |  缺  |  缺  |  缺  |  缺  |  缺  |  缺  |  缺  |      |      |  缺  |  缺  |  缺  |

**较为常见的实现方法**：unordered_map + list

```cpp
class LRU {
public:
    LRU(int capacity) {
        this->cap_ = capacity;
    }
    int get(int key) {
        auto it = map_.find(key);

        // 访问的 key 不存在
        if (it == map_.end()) {
            return -1;
        }

        // key 存在，把(k, v)调到队头
        pair<int, int> kv = *map_[key];
        cache.erase(map_[key]);
        cache.push_front(kv);

        // 更新(key, value)在 cache 中的位置
        map_[key] = cache.begin();
        return kv.second;
    }
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it == map_.end()) {

            // key 不存在
            if (cache.size() == cap_) {

                // cache 已满，删除尾部的键值对腾出位置
                // cache 和 map_ 中的数据都要删除
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map_.erase(lastKey);
                cache.pop_back();
            }

            // cache 没满可以直接添加
            cache.push_front(make_pair(key, value));
            map_[key] = cache.begin();
        } else {

            // key 存在更改 value 并切换到队头
            cache.erase(map_[key]);
            cache.push_front(make_pair(key, value));
            map_[key] = cache.begin();
        }
    }
private:

    // 缓存的最大容量
    int cap_;

    // 双链表，存储(key, value)元组
    list<pair<int, int>> cache;

    // 哈希表，key 映射到(key, value)在 cache 中的位置
    unordered_map<int, list<pair<int, int>>::iterator> map_;
};
```

### 线程安全的单例模式

**单例模式**：私有的构造函数、一个静态的方法，返回这个唯一实例的引用、一个指针静态变量、选择一个解决线程安全问题的方法

`int pthread_once(pthread_once_t* once_control, void (*init_routine)(void));`

功能是本函数使用初值为 PTHREAD_ONCE_INIT 的 once_control 变量保证 init_routine()函数在本进程执行序列中仅执行一次。

```cpp
template<typename T>
class Singlrton : boost::noncopyable {
public:
    static T& instance() {

        // 只调用一次 init()
        pthread_once(&once_, &Singleton::init);
        return *value;
    }
private:
    Singleton();
    ~Singleton();
    static void init() {
        value_ = new T();
    }
    static pthread_once_t once_;
    static T* value_;
};

template<typename T>
pthread_once_t Singleton<T>::once_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = nullptr;
```
