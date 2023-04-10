# CS61C-SU20
UCB的体系结构课程，核心内容：

- C和数字电路基础
- C内存管理和调试
- **RISCV基础**
- **CPU结构**（5段流水线）
- 流水线的思想、问题、解决方法
- 分支预测
- **cache**（三种映射、命中率问题、block替换、多级cache）
- **virtual memory**
- IO
- **SIMD**
- 并行和并发（以及其中的一致性问题）
- WSC（Warehouse Scale Computer）

课程主页：[CS 61C Summer 2020](https://inst.eecs.berkeley.edu/~cs61c/su20/)

PPT链接：CS61C https://www.aliyundrive.com/s/iGNMDuVKRV2 提取码: 5h8k 点击链接保存，或者复制本段内容，打开「阿里云盘」APP ，无需下载极速在线查看，视频原画倍速播放。



11个lab：从c的调试、内存管理，到riscv汇编，再到动手搭建流水线，以及在GUI中体会cache原理，应有尽有，非常好



4个project：只做了两个（皆是19fall的），第一个是用C复现著名计算机游戏：game of life，本质上就是做一些像素点处理，相对简单；

第二个是用riscv实现一个神经网络识别mnist手写数字（仅前向，无back propagation），用汇编写神经网络，相当之炸裂；

第三个是用可视化软件搭一个5段流水cpu，没做，可参考[这个repo][https://github.com/haohuaijin/CS61C]；

第四个是用 OpenMP, SIMD 等方法并行优化矩阵运算，实现一个简易的 Numpy，也没做，并且网上普遍不推荐做，好像有什么bug



上述代码运行环境建议：wsl + vscode remote，相当之丝滑
