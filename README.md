# numerical_proof_generator
数 字 论 证 生成器

这么臭的代码有什么写的必要吗

用逆波兰式往int array里填充0-5的数字（特例：-1，代表-1，仅在array的第一个元素使用），然后灌进stack里转换成数字和运算符号并进行计算，如果匹配就转换成逆波兰式输出。

详情：http://www.bugting.com/numerical_proof_generator.html

10/02/2018: 把输出搞定了；加入了幂运算；加入了允许用户自己输入论证的数的功能；把垃圾代码清理掉了。（现在应该算是第一个稳定版本？

11/18/2018: 实现了弱算术论证和迫真论证。为了支持弱算术论证，代码上改动不小，现在可以对输入数字以任意数字基础进行论证（比如只用1，14，5，14）。另外加入了新的“求和论证”（把目标数字的各个位数加起来进行数字论证）。现在在计划把数字论证助手做成android app。

12/25/2018：把Android app做出来了，放到另一个repo里了：https://github.com/AlexZhaoZt/NumericalProofGeneratorApp 这样可以保持源码整洁。（不会操作branch的手残的借口
